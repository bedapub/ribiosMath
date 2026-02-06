## Test environments

* Local: Linux Mint 21.2 (x86_64), R 4.5.2
* GitHub Actions:
  - Windows (R release)
  - macOS (R release, R devel)
  - Ubuntu (R release, R oldrel)

## R CMD check results

0 errors | 0 warnings | 1 note

The NOTE is for new CRAN submission (first-time package).

## Notes for CRAN reviewers

This package provides mathematical and statistical tools for computational
biology in drug discovery, developed at F. Hoffmann-La Roche AG.

Key functionality includes:
- Cosine similarity and distance calculations
- Kappa statistics for clustering (DAVID algorithm implementation)
- Density-based simulations

The package uses Rcpp and RcppArmadillo for high-performance computations.
