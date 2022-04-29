// KRATOS___
//     //   ) )
//    //         ___      ___
//   //  ____  //___) ) //   ) )
//  //    / / //       //   / /
// ((____/ / ((____   ((___/ /  MECHANICS
//
//  License:         geo_mechanics_application/license.txt
//
//  Main authors:    Aron Noordam
//

#if !defined(KRATOS_GEO_STEADY_STATE_PW_PIPING_ELEMENT_H_INCLUDED )
#define  KRATOS_GEO_STEADY_STATE_PW_PIPING_ELEMENT_H_INCLUDED

// Project includes
#include "includes/serializer.h"

// Application includes
#include "custom_elements/steady_state_Pw_interface_element.hpp"
#include "custom_utilities/interface_element_utilities.hpp"
#include "geo_mechanics_application_variables.h"

namespace Kratos
{

template< unsigned int TDim, unsigned int TNumNodes >
class KRATOS_API(GEO_MECHANICS_APPLICATION) SteadyStatePwPipingElement :
    public SteadyStatePwInterfaceElement<TDim,TNumNodes>
{

public:

    KRATOS_CLASS_INTRUSIVE_POINTER_DEFINITION( SteadyStatePwPipingElement );

    typedef SteadyStatePwInterfaceElement<TDim, TNumNodes> BaseType;

    typedef std::size_t IndexType;
    typedef Properties PropertiesType;
    typedef Node <3> NodeType;
    typedef Geometry<NodeType> GeometryType;
    typedef Geometry<NodeType>::PointsArrayType NodesArrayType;
    typedef Vector VectorType;
    typedef Matrix MatrixType;

    typedef Element::DofsVectorType DofsVectorType;
    typedef Element::EquationIdVectorType EquationIdVectorType;

    /// The definition of the sizetype
    typedef std::size_t SizeType;

    using BaseType::mRetentionLawVector;
    using BaseType::mThisIntegrationMethod;
    using BaseType::CalculateRetentionResponse;

    typedef typename BaseType::InterfaceElementVariables InterfaceElementVariables;
    typedef typename BaseType::SFGradAuxVariables SFGradAuxVariables;

///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    /// Default Constructor
    SteadyStatePwPipingElement(IndexType NewId = 0) : SteadyStatePwInterfaceElement<TDim,TNumNodes>( NewId ) {}

    /// Constructor using an array of nodes
    SteadyStatePwPipingElement(IndexType NewId,
                                const NodesArrayType& ThisNodes) : SteadyStatePwInterfaceElement<TDim,TNumNodes>(NewId, ThisNodes) {}

    /// Constructor using Geometry
    SteadyStatePwPipingElement(IndexType NewId,
                                GeometryType::Pointer pGeometry) : SteadyStatePwInterfaceElement<TDim,TNumNodes>(NewId, pGeometry) {}

    /// Constructor using Properties
    SteadyStatePwPipingElement(IndexType NewId,
                                GeometryType::Pointer pGeometry,
                                PropertiesType::Pointer pProperties)
                                : SteadyStatePwInterfaceElement<TDim,TNumNodes>( NewId, pGeometry, pProperties )
    {}

    /// Destructor
    ~SteadyStatePwPipingElement() override {}

///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    Element::Pointer Create(IndexType NewId,
                            NodesArrayType const& ThisNodes,
                            PropertiesType::Pointer pProperties) const override;

    Element::Pointer Create(IndexType NewId,
                            GeometryType::Pointer pGeom,
                            PropertiesType::Pointer pProperties) const override;

    void Initialize(const ProcessInfo& rCurrentProcessInfo) override;

    int Check(const ProcessInfo& rCurrentProcessInfo) const override;

    bool InEquilibrium(const PropertiesType& Prop, const GeometryType& Geom);

    double CalculateWaterPressureGradient(const PropertiesType& Prop, const GeometryType& Geom, double pipe_length);

    double CalculateEquilibriumPipeHeight(const PropertiesType& Prop, const GeometryType& Geom, double dx);

    void CalculateLength(const GeometryType& Geom);

    double pipe_height;

    double pipe_length;

protected:
    
     void CalculateAll( MatrixType& rLeftHandSideMatrix,
                        VectorType& rRightHandSideVector,
                        const ProcessInfo& CurrentProcessInfo,
                        const bool CalculateStiffnessMatrixFlag,
                        const bool CalculateResidualVectorFlag) override;

   

    

    double CalculateParticleDiameter(const PropertiesType& Prop);
    
///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

private:

    /// Member Variables

///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    /// Serialization

    friend class Serializer;

    void save(Serializer& rSerializer) const override
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS( rSerializer, Element )
    }

    void load(Serializer& rSerializer) override
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS( rSerializer, Element )
    }

    /// Assignment operator.
    SteadyStatePwPipingElement& operator=(SteadyStatePwPipingElement const& rOther);

    /// Copy constructor.
    SteadyStatePwPipingElement(SteadyStatePwInterfaceElement const& rOther);

}; // Class SteadyStatePwInterfaceElement

} // namespace Kratos

#endif // KRATOS_GEO_STEADY_STATE_PW_PIPING_ELEMENT_H_INCLUDED  defined