#' Simulate from density
#'
#' Compared with bootstrapping, the results do not reveal input values, and the
#' empirical distribution can be smoother. The function assumes that the distribution
#' can be aproximated using a gaussian kernel.
#' @param vec Numeric vector
#' @param N Integer, number of simulated instances
#' @author Iakov Davydov
#' @examples
#' my_vec <- c(23, 27, 26, 24, 25)
#' simulate_from_density(my_vec, 10)
#' @importFrom stats bw.SJ rnorm
#' @export
simulate_from_density <- function(vec, N = 1e5) {
  rnorm(N, sample(vec, size = N, replace = TRUE), bw.SJ(vec))
}
