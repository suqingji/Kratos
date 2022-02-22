#!/bin/bash

# Function to add apps
add_app () {
    export KRATOS_APPLICATIONS="${KRATOS_APPLICATIONS}$1;"
}

# Set variables
export KRATOS_SOURCE=${KRATOS_ROOT}
export KRATOS_BUILD="${KRATOS_SOURCE}/build"
export KRATOS_APP_DIR="${KRATOS_SOURCE}/applications"
# export KRATOS_INSTALL_PYTHON_USING_LINKS=ON

export KRATOS_BUILD_TYPE="Release"
export PYTHON_EXECUTABLE=$1

# Set applications to compile
export KRATOS_APPLICATIONS=
add_app ${KRATOS_APP_DIR}/StructuralMechanicsApplication
add_app ${KRATOS_APP_DIR}/FluidDynamicsApplication
add_app ${KRATOS_APP_DIR}/DEMApplication
add_app ${KRATOS_APP_DIR}/ContactStructuralMechanicsApplication
add_app ${KRATOS_APP_DIR}/ParticleMechanicsApplication;
add_app ${KRATOS_APP_DIR}/ConvectionDiffusionApplication;
add_app ${KRATOS_APP_DIR}/DamApplication;
add_app ${KRATOS_APP_DIR}/PoromechanicsApplication;
add_app ${KRATOS_APP_DIR}/FSIApplication;
add_app ${KRATOS_APP_DIR}/SwimmingDEMApplication;
add_app ${KRATOS_APP_DIR}/LinearSolversApplication;
add_app ${KRATOS_APP_DIR}/ConstitutiveLawsApplication;
# add_app ${KRATOS_APP_DIR}/FemToDemApplication;
# add_app ${KRATOS_APP_DIR}/PfemFluidDynamicsApplication;
add_app ${KRATOS_APP_DIR}/DelaunayMeshingApplication;
add_app ${KRATOS_APP_DIR}/MeshingApplication;
add_app ${KRATOS_APP_DIR}/MetisApplication;
add_app ${KRATOS_APP_DIR}/DemStructuresCouplingApplication;
add_app ${KRATOS_APP_DIR}/MeshMovingApplication;
add_app ${KRATOS_APP_DIR}/CSharpWrapperApplication;
add_app ${KRATOS_APP_DIR}/ShapeOptimizationApplication;
add_app ${KRATOS_APP_DIR}/CoSimulationApplication;
# add_app ${KRATOS_APP_DIR}/CableNetApplication;
add_app ${KRATOS_APP_DIR}/RANSApplication;
add_app ${KRATOS_APP_DIR}/MappingApplication;
add_app ${KRATOS_APP_DIR}/CompressiblePotentialFlowApplication;
# add_app ${KRATOS_APP_DIR}/HDF5Application;
add_app ${KRATOS_APP_DIR}/IgaApplication;
add_app ${KRATOS_APP_DIR}/ChimeraApplication;
add_app ${KRATOS_APP_DIR}/MultilevelMonteCarloApplication;
add_app ${KRATOS_APP_DIR}/StatisticsApplication;
add_app ${KRATOS_APP_DIR}/RomApplication;

# Clean
rm -rf "${KRATOS_BUILD}/${KRATOS_BUILD_TYPE}/cmake_install.cmake"
rm -rf "${KRATOS_BUILD}/${KRATOS_BUILD_TYPE}/CMakeCache.txt"
rm -rf "${KRATOS_BUILD}/${KRATOS_BUILD_TYPE}/CMakeFiles"

${CMAKE} -H"${KRATOS_SOURCE}" -B"${KRATOS_BUILD}/${KRATOS_BUILD_TYPE}" \
-DCMAKE_INSTALL_PREFIX=$2                                              \
-DUSE_TRIANGLE_NONFREE_TPL=ON                                          \
-DUSE_MPI=ON                                                           \
-DCMAKE_C_COMPILER=/usr/lib64/mpich/bin/mpicc                          \
-DCMAKE_CXX_COMPILER=/usr/lib64/mpich/bin/mpicxx                       \
-DCMAKE_CXX_FLAGS="-msse3 -std=c++11 "                                 \
-DCMAKE_C_FLAGS="-msse3"                                               \
-DBOOST_ROOT="/workspace/boost/boost_1_71_0"                           \
-DINCLUDE_MMG=ON                                                       \
-DMMG_ROOT="/workspace/external_libraries/mmg/mmg_5_4_1"               \
-DINSTALL_RUNKRATOS=OFF