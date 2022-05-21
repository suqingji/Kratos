---
title: Adjoint approach
keywords: 
tags: [Adjoint_approach.md]
sidebar: shape_optimization_application
summary: 
---
On the contrary to the direct approach, the adjoint approach starts from the Lagrangian formulation of the unconstrained optimization problem:

![f1]

where F is the objective function, S is the set of state equations and **u**<sup>*</sup> are the discrete adjoint variables of the state variables acting as Lagrangian multipliers. Differentiating and solving for the adjoint variables, we obtain

![f2]

Substituting in the derivative of the Lagrangian formulation gives:

![f3]

The adjoint variables are evaluated once per state equation, making this the preferred approach for cases where the number of state equations is smaller than the number of design variables.

### References
- Bletzinger, K.-U. (2017). Shape Optimization. In Encyclopedia of Computational Mechanics Second Edition (eds E. Stein, R. Borst and T.J.R. Hughes). https://doi.org/10.1002/9781119176817.ecm2109

[f1]: https://latex.codecogs.com/png.image?\inline&space;\dpi{110}\bg{white}L=F(\mathbf{s},\mathbf{u})&plus;\mathbf{u}^{*T}\mathbf{S}(\mathbf{s},\mathbf{u})
[f2]: https://latex.codecogs.com/png.image?\inline&space;\dpi{110}\bg{white}\mathbf{u}^*=-\mathbf{S}_u^{-T}F_u
[f3]: https://latex.codecogs.com/png.image?\inline&space;\dpi{110}\bg{white}\dfrac{dF}{ds}=F_s&plus;\mathbf{u}^{*T}\mathbf{S}_s