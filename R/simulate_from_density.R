#' Simulate from density
#' Compared with bootstrapping, the results do not reveal input values, and the
#' empirical distribution can be smoother. The function assumes that the data
#' is normally distributed.
#' @param vec Numeric vector
#' @param N Integer, number of simulated instances
#' @author Iakov Davydov
#' @examples
#' my_vec <- c(23, 27, 26, 24, 25)
#' simulate_from_density(my_vec, 10)
#' @importFrom stats density rnorm
#' @export
simulate_from_density <- function(vec, N = 1e5) {
  fit <- density(vec, bw="SJ")
  rnorm(N, sample(vec, size = N, replace = TRUE), fit$bw)
}
