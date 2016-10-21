# Utilities.R
# Author: Matt Piekenbrock
# Description: Set of basic (sometimes trivial) utility functions and definitions to add to the global environment upon
# sourcing the document. If adding to the list, please add at least one line comment/documentation.

# Shorter length function
len <- function(x) length (x)

# Count the number of unique objects in a vector
nuniq <- function(x) {
  length(unique(x))
}

# Number of instances of 'elem' in vector 'x'
# Accepts either logical statement (count # of trues) or a vector and element to count
ncount <- function(x, elem) {
  if ("logical" %in% class(x)) return(length(which(x)))
  table(x)[[as.character(elem)]]
}

#  Compute the normalized frequency probability mass estimates of given sample
Pr <- function(X) { pmf <- tabulate(as.factor(X))/sum(tabulate(as.factor(X))); names(pmf) <- levels(as.factor(X)); pmf }

# Entropy calculation
H <- function(X, base=2) {
  if (sum(X) == 1) {
    X <- X[which(X > 0)]
    -sum(sapply(X, function(p_x) p_x * log(p_x, base)))
  } else { stop(paste("Invalid PMF passed in:", str(X))) }
}

# KL Divergence
# The support of P should be given via the names attribute
D <- function(P, Q, base=2) {
  if (is.null(names(P))) stop("Support of P must be specified via names attribute")
  sum(sapply(names(P), function(i) P[[i]] * log(P[[i]]/Q[[i]], base)))
}

# Mutual Information
I <- function(XY, base=2) { H(rowSums(XY)) + H(colSums(XY)) - H(XY) }
