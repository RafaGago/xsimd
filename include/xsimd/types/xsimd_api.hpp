#ifndef XSIMD_API_HPP
#define XSIMD_API_HPP

#include "../types/xsimd_batch.hpp"
#include "../arch/xsimd_isa.hpp"

#include <limits>
#include <ostream>

namespace xsimd {

/**
 * high level free functions
 *
 * @defgroup batch_arithmetic Arithmetic operators
 * @defgroup batch_constant Constant batches
 * @defgroup batch_data_transfer Memory operators
 * @defgroup batch_math Basic math operators
 * @defgroup batch_math_extra Extra math operators
 * @defgroup batch_fp Floating point manipulation
 * @defgroup batch_rounding Rounding operators
 * @defgroup batch_conversion Conversion operators
 * @defgroup batch_complex_op Complex operators
 * @defgroup batch_logical Logical operators
 * @defgroup batch_bitwise Bitwise operators
 * @defgroup batch_reducers Reducers
 * @defgroup batch_miscellaneous Miscellaneous
 * @defgroup batch_trigo Trigonometry
 *
 * @defgroup batch_bool_logical Boolean logical operators
 * @defgroup batch_bool_reducers Boolean reducers
 */

/**
 * @ingroup batch_math
 *
 * Computes the absolute values of each scalar in the batch \c x.
 * @param x batch of integer or floating point values.
 * @return the absolute values of \c x.
 */
template<class T, class A>
batch<T, A> abs(batch<T, A> const& x) {
  return kernel::abs<A>(x, A{});
}

/**
 * @ingroup batch_complex
 *
 * Computes the absolute values of each complex in the batch \c z.
 * @param z batch of complex values.
 * @return the absolute values of \c z.
 */
template<class T, class A>
batch<T, A> abs(batch<std::complex<T>, A> const& z) {
  return kernel::abs<A>(z, A{});
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes the sum of the batches \c x and \c y.
 * @param x batch or scalar involved in the addition.
 * @param y batch or scalar involved in the addition.
 * @return the sum of \c x and \c y
 */
template<class T, class Tp>
auto add(T const& x, Tp const& y) -> decltype(x + y){
  return x + y;
}

/**
 * @ingroup batch_trigo
 *
 * Computes the arc cosine of the batch \c x.
 * @param x batch of floating point values.
 * @return the arc cosine of \c x.
 */
template<class T, class A>
batch<T, A> acos(batch<T, A> const& x) {
  return kernel::acos<A>(x, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the inverse hyperbolic cosine of the batch \c x.
 * @param x batch of floating point values.
 * @return the inverse hyperbolic cosine of \c x.
 */
template<class T, class A>
batch<T, A> acosh(batch<T, A> const& x) {
  return kernel::acosh<A>(x, A{});
}

/**
 * @ingroup batch_complex
 *
 * Computes the argument of the batch \c z.
 * @param z batch of complex values.
 * @return the argument of \c z.
 */
template<class T, class A>
batch<T, A> arg(batch<std::complex<T>, A> const& z) {
  return kernel::arg<A>(z, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the arc sine of the batch \c x.
 * @param x batch of floating point values.
 * @return the arc sine of \c x.
 */
template<class T, class A>
batch<T, A> asin(batch<T, A> const& x) {
  return kernel::asin<A>(x, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the inverse hyperbolic sine of the batch \c x.
 * @param x batch of floating point values.
 * @return the inverse hyperbolic sine of \c x.
 */
template<class T, class A>
batch<T, A> asinh(batch<T, A> const& x) {
  return kernel::asinh<A>(x, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the arc tangent of the batch \c x.
 * @param x batch of floating point values.
 * @return the arc tangent of \c x.
 */
template<class T, class A>
batch<T, A> atan(batch<T, A> const& x) {
  return kernel::atan<A>(x, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the arc tangent of the batch \c x/y, using the signs of the
 * arguments to determine the correct quadrant.
 * @param x batch of floating point values.
 * @param y batch of floating point values.
 * @return the arc tangent of \c x/y.
 */
template<class T, class A>
batch<T, A> atan2(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::atan2<A>(x, y, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the inverse hyperbolic tangent of the batch \c x.
 * @param x batch of floating point values.
 * @return the inverse hyperbolic tangent of \c x.
 */
template<class T, class A>
batch<T, A> atanh(batch<T, A> const& x) {
  return kernel::atanh<A>(x, A{});
}

/**
 * @ingroup batch_conversion
 *
 * Perform a static_cast from \c T_in to \c T_out on \c \c x.
 * @param x batch of \c T_in
 * @return \c x casted to \c T_out
 */
template<class T_out, class T_in, class A>
batch<T_out, A> batch_cast(batch<T_in, A> const & x) {
  return kernel::batch_cast<A>(x, batch<T_out, A>{}, A{});
}

/**
 * @ingroup batch_miscellaneous
 *
 * Computes the bit of sign of \c x
 * @param x batch of scalar
 * @return bit of sign of \c x
 */
template<class T, class A>
batch<T, A> bitofsign(batch<T, A> const& x) {
  return kernel::bitofsign<A>(x, A{});
}

/**
 * @ingroup batch_bitwise
 *
 * Computes the bitwise and of the batches \c x and \c y.
 * @param x batch involved in the operation.
 * @param y batch involved in the operation.
 * @return the result of the bitwise and.
 */
template<class T, class Tp>
auto bitwise_and(T const& x, Tp const& y) -> decltype(x & y){
  return x & y;
}

/**
 * @ingroup batch_bitwise
 *
 * Computes the bitwise and not of batches \c x and \c y.
 * @param x batch involved in the operation.
 * @param y batch involved in the operation.
 * @return the result of the bitwise and not.
 */
template<class T, class A>
batch<T, A> bitwise_andnot(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::bitwise_andnot<A>(x, y, A{});
}


/**
 * @ingroup batch_bool_logical
 *
 * Computes the bitwise and not of batches \c x and \c y.
 * @param x batch involved in the operation.
 * @param y batch involved in the operation.
 * @return the result of the bitwise and not.
 */
template<class T, class A>
batch_bool<T, A> bitwise_andnot(batch_bool<T, A> const& x, batch_bool<T, A> const& y) {
  return kernel::bitwise_andnot<A>(x, y, A{});
}

/**
 * @ingroup batch_conversion
 *
 * Perform a reinterpret_cast from \c T_in to \c T_out on \c x.
 * @param x batch of \c T_in
 * @return \c x reinterpreted as \c T_out
 */
template<class B, class T, class A>
B bitwise_cast(batch<T, A> const& x) {
  return kernel::bitwise_cast<A>(x, B{}, A{});
}

/**
 * @ingroup batch_bitwise
 *
 * Computes the bitwise not of batch \c x.
 * @param x batch involved in the operation.
 * @return the result of the bitwise not.
 */
template<class T, class A>
batch<T, A> bitwise_not(batch<T, A> const& x) {
  return kernel::bitwise_not<A>(x, A{});
}

/**
 * @ingroup batch_bitwise
 *
 * Computes the bitwise or of the batches \c x and \c y.
 * @param x scalar or batch of scalars
 * @param y scalar or batch of scalars
 * @return the result of the bitwise or.
 */
template<class T, class Tp>
auto bitwise_or(T const& x, Tp const& y) -> decltype(x | y){
  return x | y;
}

/**
 * @ingroup batch_bitwise
 *
 * Computes the bitwise xor of the batches \c x and \c y.
 * @param x scalar or batch of scalars
 * @param y scalar or batch of scalars
 * @return the result of the bitwise xor.
 */
template<class T, class Tp>
auto bitwise_xor(T const& x, Tp const& y) -> decltype(x ^ y){
  return x ^ y;
}

// FIXME: check if these need to be exposed, or removed (?)
template<class A>
batch_bool<float, A> bool_cast(batch_bool<int32_t, A> const& x) {
  return kernel::bool_cast<A>(x, A{});
}
template<class A>
batch_bool<int32_t, A> bool_cast(batch_bool<float, A> const& x) {
  return kernel::bool_cast<A>(x, A{});
}
template<class A>
batch_bool<double, A> bool_cast(batch_bool<int64_t, A> const& x) {
  return kernel::bool_cast<A>(x, A{});
}
template<class A>
batch_bool<int64_t, A> bool_cast(batch_bool<double, A> const& x) {
  return kernel::bool_cast<A>(x, A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Creates a batch from the single value \c v.
 * @param v the value used to initialize the batch
 * @return a new batch instance
 */
template<class T, class A=default_arch>
batch<T, A> broadcast(T v) {
  return kernel::broadcast<A>(v, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the cubic root of the batch \c x.
 * @param x batch of floating point values.
 * @return the cubic root of \c x.
 */
template<class T, class A>
batch<T, A> cbrt(batch<T, A> const& x) {
  return kernel::cbrt<A>(x, A{});
}

/**
 * @ingroup batch_rounding
 *
 * Computes the batch of smallest integer values not less than
 * scalars in \c x.
 * @param x batch of floating point values.
 * @return the batch of smallest integer values not less than \c x.
 */
template<class T, class A>
batch<T, A> ceil(batch<T, A> const& x) {
  return kernel::ceil<A>(x, A{});
}


/**
 * @ingroup batch_math
 *
 * Clips the values of the batch \c x between those of the batches \c lo and \c hi.
 * @param x batch of floating point values.
 * @param lo batch of floating point values.
 * @param hi batch of floating point values.
 * @return the result of the clipping.
 */
template<class A, class T>
batch<T, A> clip(batch<T, A> const& x, batch<T, A> const& lo, batch<T, A> const& hi) {
  return kernel::clip(x, lo, hi, A{});
}

/**
 * @ingroup batch_complex
 *
 * Computes the conjugate of the batch \c z.
 * @param z batch of complex values.
 * @return the argument of \c z.
 */
template<class A, class T>
batch<std::complex<T>, A> conj(batch<std::complex<T>, A> const& z) {
  return kernel::conj(z, A{});
}

/**
 * @ingroup batch_miscellaneous
 *
 * Computes a value whose  absolute  value  matches
 *        that of \c x, but whose sign bit matches that of \c y.
 * @param x batch of scalars
 * @param y batch of scalars
 * @return batch whose absolute  value  matches that of \c x, but whose sign bit
 * matches that of \c y.
 */
template<class A, class T>
batch<T, A> copysign(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::copysign<A>(x, y, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the cosine of the batch \c x.
 * @param x batch of floating point values.
 * @return the cosine of \c x.
 */
template<class T, class A>
batch<T, A> cos(batch<T, A> const& x) {
  return kernel::cos<A>(x, A{});
}

/**
 * @ingroup batch_trigo
 *
 * computes the hyperbolic cosine of the batch \c x.
 * @param x batch of floating point values.
 * @return the hyperbolic cosine of \c x.
 */
template<class T, class A>
batch<T, A> cosh(batch<T, A> const& x) {
  return kernel::cosh<A>(x, A{});
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes the division of the batch \c x by the batch \c y.
 * @param x scalar or batch of scalars
 * @param y scalar or batch of scalars
 * @return the result of the division.
 */
template<class T, class Tp>
auto div(T const& x, Tp const& y) -> decltype(x / y){
  return x / y;
}

/**
 * @ingroup batch_logical
 *
 * Element-wise equality comparison of batches \c x and \c y.
 * @param x batch of scalars
 * @param y batch of scalars
 * @return a boolean batch.
 */
template<class T, class A>
batch_bool<T, A> eq(batch<T, A> const& x, batch<T, A> const& y) {
  return x == y;
}

/**
 * @ingroup batch_math
 *
 * Computes the natural exponential of the batch \c x.
 * @param x batch of floating point values.
 * @return the natural exponential of \c x.
 */
template<class T, class A>
batch<T, A> exp(batch<T, A> const& x) {
  return kernel::exp<A>(x, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the base 10 exponential of the batch \c x.
 * @param x batch of floating point values.
 * @return the base 10 exponential of \c x.
 */
template<class T, class A>
batch<T, A> exp10(batch<T, A> const& x) {
  return kernel::exp10<A>(x, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the base 2 exponential of the batch \c x.
 * @param x batch of floating point values.
 * @return the base 2 exponential of \c x.
 */
template<class T, class A>
batch<T, A> exp2(batch<T, A> const& x) {
  return kernel::exp2<A>(x, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the natural exponential of the batch \c x, minus one.
 * @param x batch of floating point values.
 * @return the natural exponential of \c x, minus one.
 */
template<class T, class A>
batch<T, A> expm1(batch<T, A> const& x) {
  return kernel::expm1<A>(x, A{});
}

/**
 * @ingroup batch_math_extra
 *
 * Computes the error function of the batch \c x.
 * @param x batch of floating point values.
 * @return the error function of \c x.
 */
template<class T, class A>
batch<T, A> erf(batch<T, A> const& x) {
  return kernel::erf<A>(x, A{});
}

/**
 * @ingroup batch_math_extra
 *
 * Computes the complementary error function of the batch \c x.
 * @param x batch of floating point values.
 * @return the error function of \c x.
 */
template<class T, class A>
batch<T, A> erfc(batch<T, A> const& x) {
  return kernel::erfc<A>(x, A{});
}

/**
 * @ingroup batch_math_extra
 *
 * Evaluate polynomial with coefficient \c Coefs on point \c x using estrin
 * method.
 * @param x batch of floating point values.
 * @return the evaluation ofpolynomial with coefficient \c Coefs on point \c x.
 */
template <class T, class A, uint64_t... Coefs>
batch<T, A> estrin(const batch<T, A>& x) {
  return kernel::estrin<T, A, Coefs...>(x);
}

/**
 * Extract vector from pair of vectors
 * extracts the lowest vector elements from the second source \c x
 * and the highest vector elements from the first source \c y
 * Concatenates the results into th Return value.
 * @param x batch of integer or floating point values.
 * @param y batch of integer or floating point values.
 * @param i integer specifuing the lowest vector element to extract from the first source register
 * @return.
 */
template <class T, class A>
batch<T, A> extract_pair(batch<T, A> const & x, batch<T, A> const& y, std::size_t i) {
  return kernel::extract_pair<A>(x, y, i, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the absolute values of each scalar in the batch \c x.
 * @param x batch floating point values.
 * @return the asbolute values of \c x.
 */
template<class T, class A>
batch<T, A> fabs(batch<T, A> const& x) {
  return kernel::abs<A>(x, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the positive difference between \c x and \c y, that is,
 * <tt>max(0, x-y)</tt>.
 * @param x batch of floating point values.
 * @param y batch of floating point values.
 * @return the positive difference.
 */
template<class T, class A>
batch<T, A> fdim(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::fdim<A>(x, y, A{});
}

/**
 * @ingroup batch_rounding
 *
 * Computes the batch of largest integer values not greater than
 * scalars in \c x.
 * @param x batch of floating point values.
 * @return the batch of largest integer values not greater than \c x.
 */
template<class T, class A>
batch<T, A> floor(batch<T, A> const& x) {
  return kernel::floor<A>(x, A{});
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes <tt>(x*y) + z</tt> in a single instruction when possible.
 * @param x a batch of integer or floating point values.
 * @param y a batch of integer or floating point values.
 * @param z a batch of integer or floating point values.
 * @return the result of the fused multiply-add operation.
 */
template<class T, class A>
batch<T, A> fma(batch<T, A> const& x, batch<T, A> const& y, batch<T, A> const& z) {
  return kernel::fma<A>(x, y, z, A{});
}


/**
 * @ingroup batch_math
 *
 * Computes the larger values of the batches \c x and \c y.
 * @param x a batch of integer or floating point values.
 * @param y a batch of integer or floating point values.
 * @return a batch of the larger values.
 */
template<class T, class A>
batch<T, A> fmax(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::max<A>(x, y, A{});
}


/**
 * @ingroup batch_math
 *
 * Computes the smaller values of the batches \c x and \c y.
 * @param x a batch of integer or floating point values.
 * @param y a batch of integer or floating point values.
 * @return a batch of the larger values.
 */
template<class T, class A>
batch<T, A> fmin(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::min<A>(x, y, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the modulo of the batch \c x by the batch \c y.
 * @param x batch involved in the modulo.
 * @param y batch involved in the modulo.
 * @return the result of the modulo.
 */
template<class T, class A>
batch<T, A> fmod(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::fmod<A>(x, y, A{});
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes <tt>(x*y) - z</tt> in a single instruction when possible.
 * @param x a batch of integer or floating point values.
 * @param y a batch of integer or floating point values.
 * @param z a batch of integer or floating point values.
 * @return the result of the fused multiply-sub operation.
 */
template<class T, class A>
batch<T, A> fms(batch<T, A> const& x, batch<T, A> const& y, batch<T, A> const& z) {
  return kernel::fms<A>(x, y, z, A{});
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes <tt>-(x*y) + z</tt> in a single instruction when possible.
 * @param x a batch of integer or floating point values.
 * @param y a batch of integer or floating point values.
 * @param z a batch of integer or floating point values.
 * @return the result of the fused negated multiply-add operation.
 */
template<class T, class A>
batch<T, A> fnma(batch<T, A> const& x, batch<T, A> const& y, batch<T, A> const& z) {
  return kernel::fnma<A>(x, y, z, A{});
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes <tt>-(x*y) - z</tt> in a single instruction when possible.
 * @param x a batch of integer or floating point values.
 * @param y a batch of integer or floating point values.
 * @param z a batch of integer or floating point values.
 * @return the result of the fused negated multiply-sub operation.
 */
template<class T, class A>
batch<T, A> fnms(batch<T, A> const& x, batch<T, A> const& y, batch<T, A> const& z) {
  return kernel::fnms<A>(x, y, z, A{});
}

/**
 * @ingroup batch_fp
 *
 * Split split the number x into a normalized fraction and an exponent which is stored in exp
 * @param x a batch of integer or floating point values.
 * @param y a batch of integer or floating point values.
 * @return the normalized fraction of x
 */
template <class T, class A>
batch<T, A> frexp(const batch<T, A>& x, batch<as_integer_t<T>, A>& y) {
  return kernel::frexp<A>(x, y, A{});
}

/**
 * @ingroup batch_logical
 *
 * Element-wise greater or equal comparison of batches \c x and \c y.
 * @tparam X the actual type of batch.
 * @param x batch involved in the comparison.
 * @param y batch involved in the comparison.
 * @return a boolean batch.
 */
template<class T, class A>
batch_bool<T, A> ge(batch<T, A> const& x, batch<T, A> const& y) {
  return x >= y;
}

/**
 * @ingroup batch_logical
 *
 * Element-wise greater than comparison of batches \c x and \c y.
 * @tparam X the actual type of batch.
 * @param x batch involved in the comparison.
 * @param y batch involved in the comparison.
 * @return a boolean batch.
 */
template<class T, class A>
batch_bool<T, A> gt(batch<T, A> const& x, batch<T, A> const& y) {
  return x > y;
}

/**
 * @ingroup batch_reducers
 *
 * Adds all the scalars of the batch \c x.
 * @param x batch involved in the reduction
 * @return the result of the reduction.
 */
template<class T, class A>
T hadd(batch<T, A> const& x) {
  return kernel::hadd<A>(x, A{});
}

/**
 * @ingroup batch_reducers
 *
 * Parallel horizontal addition: adds the scalars of each batch
 * in the array pointed by \c row and store them in a returned
 * batch.
 * @param row an array of \c N batches
 * @return the result of the reduction.
 */
template<class T, class A>
batch<T, A> haddp(batch<T, A> const* row) {
  return kernel::haddp<A>(row, A{});
}


/**
 * @ingroup batch_math_extra
 *
 * Evaluate polynomial with coefficient \c Coefs on point \c x using horner
 * method.
 * @param x batch of floating point values.
 * @return the evaluation ofpolynomial with coefficient \c Coefs on point \c x.
 */
template <class T, class A, uint64_t... Coefs>
batch<T, A> horner(const batch<T, A>& x) {
  return kernel::horner<T, A, Coefs...>(x);
}

/**
 * @ingroup batch_math
 *
 * Computes the square root of the sum of the squares of the batches
 * \c x, and \c y.
 * @param x batch of floating point values.
 * @param y batch of floating point values.
 * @return the square root of the sum of the squares of \c x and \c y.
 */
template<class T, class A>
batch<T, A> hypot(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::hypot<A>(x, y, A{});
}


/**
 * @ingroup batch_constant
 *
 * Return a batch of scalars representing positive infinity
 * @return a batch of positive infinity
 */
template<class B>
B infinity() {
  using T = typename B::value_type;
  return B(std::numeric_limits<T>::infinity());
}

/**
 * @ingroup batch_logical
 *
 * Determines if the scalars in the given batch \c x represent an even integer value
 * @param x batch of floating point values.
 * @return a batch of booleans.
 */
template<class T, class A>
batch_bool<T, A> is_even(batch<T, A> const& x) {
  return kernel::is_even<A>(x, A{});
}

/**
 * @ingroup batch_logical
 *
 * Determines if the floating-point scalars in the given batch \c x represent integer value
 * @param x batch of floating point values.
 * @return a batch of booleans.
 */
template<class T, class A>
batch_bool<T, A> is_flint(batch<T, A> const& x) {
  return kernel::is_flint<A>(x, A{});
}

/**
 * @ingroup batch_logical
 *
 * Determines if the scalars in the given batch \c x represent an odd integer value
 * @param x batch of floating point values.
 * @return a batch of booleans.
 */
template<class T, class A>
batch_bool<T, A> is_odd(batch<T, A> const& x) {
  return kernel::is_odd<A>(x, A{});
}


/**
 * @ingroup batch_logical
 *
 * Determines if the scalars in the given batch \c x are inf values.
 * @param x batch of floating point values.
 * @return a batch of booleans.
 */
template<class T, class A>
batch_bool<T, A> isinf(batch<T, A> const& x) {
  return kernel::isinf<A>(x, A{});
}


/**
 * @ingroup batch_logical
 *
 * Determines if the scalars in the given batch \c x are finite values.
 * @param x batch of floating point values.
 * @return a batch of booleans.
 */
template<class T, class A>
batch_bool<T, A> isfinite(batch<T, A> const& x) {
  return kernel::isfinite<A>(x, A{});
}

/**
 * @ingroup batch_logical
 *
 * Determines if the scalars in the given batch \c x are NaN values.
 * @param x batch of floating point values.
 * @return a batch of booleans.
 */
template<class T, class A>
batch_bool<T, A> isnan(batch<T, A> const& x) {
  return kernel::isnan<A>(x, A{});
}

/**
 * @ingroup batch_math_extra
 *
 * Computes the multiplication of the floating- point number x by 2 raised to the power exp.
 * @param x batch of floating point values.
 * @param y batch of floating point values.
 * @return the natural logarithm of the gamma function of \c x.
 */
template <class T, class A>
batch<T, A> ldexp(const batch<T, A>& x, const batch<as_integer_t<T>, A>& y) {
  return kernel::ldexp<A>(x, y, A{});
}

/**
 * @ingroup batch_logical
 *
 * Element-wise lesser or equal to comparison of batches \c x and \c y.
 * @param x batch involved in the comparison.
 * @param y batch involved in the comparison.
 * @return a boolean batch.
 */
template<class T, class A>
batch_bool<T, A> le(batch<T, A> const& x, batch<T, A> const& y) {
  return x <= y;
}

/**
 * @ingroup batch_math_extra
 *
 * Computes the natural logarithm of the gamma function of the batch \c x.
 * @param x batch of floating point values.
 * @return the natural logarithm of the gamma function of \c x.
 */
template<class T, class A>
batch<T, A> lgamma(batch<T, A> const& x) {
  return kernel::lgamma<A>(x, A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Creates a batch from the buffer \c ptr. The
 * memory needs to be aligned.
 * @param ptr the memory buffer to read
 * @return a new batch instance
 */
template<class A=default_arch, class From>
batch<From, A> load(From const* ptr, aligned_mode= {}) {
  return kernel::load_aligned<A>(ptr, kernel::convert<From>{}, A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Creates a batch from the buffer \c ptr. The
 * memory does not need to be aligned.
 * @param ptr the memory buffer to read
 * @return a new batch instance
 */
template<class A=default_arch, class From>
batch<From, A> load(From const* ptr, unaligned_mode) {
  return kernel::load_unaligned<A>(ptr, kernel::convert<From>{}, A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Creates a batch from the buffer \c ptr. The
 * memory needs to be aligned.
 * @param ptr the memory buffer to read
 * @return a new batch instance
 */
template<class A=default_arch, class From>
batch<From, A> load_aligned(From const* ptr) {
  return kernel::load_aligned<A>(ptr, kernel::convert<From>{}, A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Creates a batch from the buffer \c ptr. The
 * memory does not need to be aligned.
 * @param ptr the memory buffer to read
 * @return a new batch instance
 */
template<class A=default_arch, class From>
batch<From, A> load_unaligned(From const* ptr) {
  return kernel::load_unaligned<A>(ptr, kernel::convert<From>{}, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the natural logarithm of the batch \c x.
 * @param x batch of floating point values.
 * @return the natural logarithm of \c x.
 */
template<class T, class A>
batch<T, A> log(batch<T, A> const& x) {
  return kernel::log<A>(x, A{});
}

/**
 * @ingroup batch_math
 * Computes the base 2 logarithm of the batch \c x.
 * @param x batch of floating point values.
 * @return the base 2 logarithm of \c x.
 */
template<class T, class A>
batch<T, A> log2(batch<T, A> const& x) {
  return kernel::log2<A>(x, A{});
}

/**
 * @ingroup batch_math
 * Computes the base 10 logarithm of the batch \c x.
 * @param x batch of floating point values.
 * @return the base 10 logarithm of \c x.
 */
template<class T, class A>
batch<T, A> log10(batch<T, A> const& x) {
  return kernel::log10<A>(x, A{});
}

/**
 * @ingroup batch_math
 * Computes the natural logarithm of one plus the batch \c x.
 * @param x batch of floating point values.
 * @return the natural logarithm of one plus \c x.
 */
template<class T, class A>
batch<T, A> log1p(batch<T, A> const& x) {
  return kernel::log1p<A>(x, A{});
}

/**
 * @ingroup batch_logical
 *
 * Element-wise lesser than comparison of batches \c x and \c y.
 * @param x batch involved in the comparison.
 * @param y batch involved in the comparison.
 * @return a boolean batch.
 */
template<class T, class A>
batch_bool<T, A> lt(batch<T, A> const& x, batch<T, A> const& y) {
  return x < y;
}

/**
 * @ingroup batch_math
 *
 * Computes the larger values of the batches \c x and \c y.
 * @param x a batch of integer or floating point values.
 * @param y a batch of integer or floating point values.
 * @return a batch of the larger values.
 */
template<class T, class A>
batch<T, A> max(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::max<A>(x, y, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the smaller values of the batches \c x and \c y.
 * @param x a batch of integer or floating point values.
 * @param y a batch of integer or floating point values.
 * @return a batch of the smaller values.
 */
template<class T, class A>
batch<T, A> min(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::min<A>(x, y, A{});
}

/**
 * @ingroup batch_constant
 *
 * Return a batch of scalars representing positive infinity
 * @return a batch of positive infinity
 */
template<class B>
B minusinfinity() {
  using T = typename B::value_type;
  return B(-std::numeric_limits<T>::infinity());
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes the integer modulo of the batch \c x by the batch \c y.
 * @param x batch involved in the modulo.
 * @param y batch involved in the modulo.
 * @return the result of the modulo.
 */
template<class T, class Tp>
auto mod(T const& x, Tp const& y) -> decltype(x % y){
  return x % y;
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes the product of the batches \c x and \c y.
 * @tparam X the actual type of batch.
 * @param x batch involved in the product.
 * @param y batch involved in the product.
 * @return the result of the product.
 */
template<class T, class Tp>
auto mul(T const& x, Tp const& y) -> decltype(x * y){
  return x * y;
}

/**
 * @ingroup batch_rounding
 *
 * Rounds the scalars in \c x to integer values (in floating point format), using
 * the current rounding mode.
 * @param x batch of flaoting point values.
 * @return the batch of nearest integer values.
 */
template<class T, class A>
batch<T, A> nearbyint(batch<T, A> const& x) {
  return kernel::nearbyint<A>(x, A{});
}

/**
 * @ingroup batch_logical
 *
 * Element-wise inequality comparison of batches \c x and \c y.
 * @param x batch involved in the comparison.
 * @param y batch involved in the comparison.
 * @return a boolean batch.
 */
template<class T, class A>
batch_bool<T, A> neq(batch<T, A> const& x, batch<T, A> const& y) {
  return x != y;
}


/**
 * @ingroup batch_arithmetic
 *
 * Computes the opposite of the batch \c x.
 * @param x batch involved in the operation.
 * @return the opposite of \c x.
 */
template<class T, class A>
batch<T, A> neg(batch<T, A> const& x) {
  return -x;
}

/**
 * @ingroup batch_math_extra
 *
 * Computes  the next representable  floating-point
 *        value  following  x  in the direction of y
 * @param x batch of floating point values.
 * @param y batch of floating point values.
 * @return \c x raised to the power \c y.
 */
template<class T, class A>
batch<T, A> nextafter(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::nextafter<A>(x, y, A{});
}

/**
 * @ingroup batch_complex
 *
 * Computes the norm of the batch \c x.
 * @param x batch of complex values.
 * @return the norm of \c x.
 */
template<class A, class T>
batch<T, A> norm(batch<std::complex<T>, A> const& x) {
  return kernel::norm(x, A{});
}

/**
 * @ingroup batch_arithmetic
 *
 * No-op on \c x.
 * @param x batch involved in the operation.
 * @return \c x.
 */
template<class T, class A>
batch<T, A> pos(batch<T, A> const& x) {
  return +x;
}

/**
 * @ingroup batch_math
 *
 * Computes the value of the batch \c x raised to the power
 * \c y.
 * @param x batch of floating point values.
 * @param y batch of floating point values.
 * @return \c x raised to the power \c y.
 */
template<class T, class A>
batch<T, A> pow(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::pow<A>(x, y, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the value of the batch \c x raised to the power
 * \c y.
 * @param x batch of integral values.
 * @param y batch of integral values.
 * @return \c x raised to the power \c y.
 */
template<class T, class ITy, class A, class=typename std::enable_if<std::is_integral<ITy>::value, void>::type>
batch<T, A> pow(batch<T, A> const& x, ITy y) {
  return kernel::ipow<A>(x, y, A{});
}

/**
 * @ingroup batch_complex
 *
 * Computes the projection of the batch \c x.
 * @param x batch of complex values.
 * @return the projection of \c x.
 */
template<class A, class T>
batch<std::complex<T>, A> proj(batch<std::complex<T>, A> const& x) {
  return kernel::proj(x, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the remainder of dividing \c x by \c y
 * @param x batch of scalar values
 * @param y batch of scalar values
 * @return the result of the addition.
 */
template<class T, class A>
batch<T, A> remainder(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::remainder<A>(x, y, A{});
}

/**
 * @ingroup batch_rounding
 *
 * Rounds the scalars in \c x to integer values (in floating point format), using
 * the current rounding mode.
 * @param x batch of floating point values.
 * @return the batch of rounded values.
 */
template<class T, class A>
batch<T, A> rint(batch<T, A> const& x) {
  return nearbyint(x);
}

/**
 * @ingroup batch_rounding
 *
 * Computes the batch of nearest integer values to scalars in \c x (in
 * floating point format), rounding halfway cases away from zero, regardless
 * of the current rounding mode.
 * @param x batch of flaoting point values.
 * @return the batch of nearest integer values. 
 */
template<class T, class A>
batch<T, A> round(batch<T, A> const& x) {
  return kernel::round<A>(x, A{});
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes the saturate sum of the batch \c x and the batch \c y.
 * \c x.
 * @tparam X the actual type of batch.
 * @param x batch involved in the saturated addition.
 * @param y batch involved in the saturated addition.
 * @return the result of the saturated addition.
 */
template<class T, class Tp>
auto sadd(T const& x, Tp const& y) -> decltype(x + y) {
  using B = decltype(x + y);
  using A = typename B::arch_type;
  return kernel::sadd<A>(B(x), B(y), A{});
}

/**
 * @ingroup batch_miscellaneous
 *
 * Ternary operator for batches: selects values from the batches \c true_br or \c false_br
 * depending on the boolean values in the constant batch \c cond. Equivalent to
 * \code{.cpp}
 * for(std::size_t i = 0; i < N; ++i)
 *     res[i] = cond[i] ? true_br[i] : false_br[i];
 * \endcode
 * @param cond constant batch condition.
 * @param true_br batch values for truthy condition.
 * @param false_br batch value for falsy condition.
 * @return the result of the selection.
 */
template<class T, class A>
batch<T, A> select(batch_bool<T, A> const& cond, batch<T, A> const& true_br, batch<T, A> const& false_br) {
  return kernel::select<A>(cond, true_br, false_br, A{});
}

/**
 * @ingroup batch_miscellaneous
 *
 * Ternary operator for batches: selects values from the batches \c true_br or \c false_br
 * depending on the boolean values in the constant batch \c cond. Equivalent to
 * \code{.cpp}
 * for(std::size_t i = 0; i < N; ++i)
 *     res[i] = cond[i] ? true_br[i] : false_br[i];
 * \endcode
 * @param cond constant batch condition.
 * @param true_br batch values for truthy condition.
 * @param false_br batch value for falsy condition.
 * @return the result of the selection.
 */
template<class T, class A>
batch<std::complex<T>, A> select(batch_bool<T, A> const& cond, batch<std::complex<T>, A> const& true_br, batch<std::complex<T>, A> const& false_br) {
  return kernel::select<A>(cond, true_br, false_br, A{});
}

/**
 * @ingroup batch_miscellaneous
 *
 * Ternary operator for batches: selects values from the batches \c true_br or \c false_br
 * depending on the boolean values in the constant batch \c cond. Equivalent to
 * \code{.cpp}
 * for(std::size_t i = 0; i < N; ++i)
 *     res[i] = cond[i] ? true_br[i] : false_br[i];
 * \endcode
 * @param cond constant batch condition.
 * @param true_br batch values for truthy condition.
 * @param false_br batch value for falsy condition.
 * @return the result of the selection.
 */
template<class T, class A, bool... Values>
batch<T, A> select(batch_bool_constant<batch<T, A>, Values...> const& cond, batch<T, A> const& true_br, batch<T, A> const& false_br) {
  return kernel::select<A>(cond, true_br, false_br, A{});
}

/**
 * @ingroup batch_miscellaneous
 *
 * Computes the sign of \c x
 * @param x batch
 * @return -1 for each negative element, -1 or +1 for each null element and +1 for each element
 */
template<class T, class A>
batch<T, A> sign(batch<T, A> const& x) {
  return kernel::sign<A>(x, A{});
}

/**
 * @ingroup batch_miscellaneous
 *
 * Computes the sign of \c x, assuming x doesn't have any zero
 * @param x batch
 * @return -1 for each negative element, -1 or +1 for each null element and +1 for each element
 */
template<class T, class A>
batch<T, A> signnz(batch<T, A> const& x) {
  return kernel::signnz<A>(x, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the sine of the batch \c x.
 * @param x batch of floating point values.
 * @return the sine of \c x.
 */
template<class T, class A>
batch<T, A> sin(batch<T, A> const& x) {
  return kernel::sin<A>(x, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the hyperbolic sine of the batch \c x.
 * @param x batch of floating point values.
 * @return the hyperbolic sine of \c x.
 */
template<class T, class A>
batch<T, A> sinh(batch<T, A> const& x) {
  return kernel::sinh<A>(x, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the sine and the cosine of the batch \c x. This method is faster
 * than calling sine and cosine independently.
 * @param x batch of floating point values.
 * @return a pair containing the sine then the cosine of  batch \c x
 */
template<class T, class A>
std::pair<batch<T, A>, batch<T, A>> sincos(batch<T, A> const& x) {
  return kernel::sincos<A>(x, A{});
}

/**
 * @ingroup batch_math
 *
 * Computes the square root of the batch \c x.
 * @param x batch of floating point values.
 * @return the square root of \c x.
 */
template<class T, class A>
batch<T, A> sqrt(batch<T, A> const& x) {
  return kernel::sqrt<A>(x, A{});
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes the saturate difference of the batch \c x and the batch \c y.
 * \c x.
 * @tparam X the actual type of batch.
 * @param x batch involved in the saturated difference.
 * @param y batch involved in the saturated difference.
 * @return the result of the saturated difference.
 */
template<class T, class Tp>
auto ssub(T const& x, Tp const& y) -> decltype(x - y) {
  using B = decltype(x + y);
  using A = typename B::arch_type;
  return kernel::ssub<A>(B(x), B(y), A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Copy content of batch \c val to the buffer \c mem. The
 * memory does not need to be aligned.
 * @param mem the memory buffer to write to
 * @param val the batch to copy from
 */
template<class To, class A, class From>
void store(From* mem, batch<To, A> const& val, aligned_mode={}) {
  return kernel::store_aligned<A>(mem, val, A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Copy content of batch \c val to the buffer \c mem. The
 * memory does not need to be aligned.
 * @param mem the memory buffer to write to
 * @param val the batch to copy from
 */
template<class To, class A, class From>
void store(To* mem, batch<From, A> const& val, unaligned_mode) {
  return kernel::store_unaligned<A>(mem, val, A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Copy content of batch \c val to the buffer \c mem. The
 * memory needs to be aligned.
 * @param mem the memory buffer to write to
 * @param val the batch to copy from
 */
template<class To, class A, class From>
void store_aligned(To* mem, batch<From, A> const& val) {
  return kernel::store_aligned<A>(mem, val, A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Copy content of batch \c val to the buffer \c mem. The
 * memory does not need to be aligned.
 * @param mem the memory buffer to write to
 * @param val the batch to copy
 */
template<class To, class A, class From>
void store_unaligned(To* mem, batch<From, A> const& val) {
  return kernel::store_unaligned<A>(mem, val, A{});
}

/**
 * @ingroup batch_arithmetic
 *
 * Computes the difference between \c x and \c y
 * @tparam X the actual type of batch.
 * @param x scalar or batch of scalars
 * @param y scalar or batch of scalars
 * @return the difference between \c x and \c y
 */
template<class T, class Tp>
auto sub(T const& x, Tp const& y) -> decltype(x - y){
  return x - y;
}

/**
 * @ingroup batch_trigo
 *
 * Computes the tangent of the batch \c x.
 * @param x batch of floating point values.
 * @return the tangent of \c x.
 */
template<class T, class A>
batch<T, A> tan(batch<T, A> const& x) {
  return kernel::tan<A>(x, A{});
}

/**
 * @ingroup batch_trigo
 *
 * Computes the hyperbolic tangent of the batch \c x.
 * @param x batch of floating point values.
 * @return the hyperbolic tangent of \c x.
 */
template<class T, class A>
batch<T, A> tanh(batch<T, A> const& x) {
  return kernel::tanh<A>(x, A{});
}

/**
 * @ingroup batch_math_extra
 *
 * Computes the gamma function of the batch \c x.
 * @param x batch of floating point values.
 * @return the gamma function of \c x.
 */
template<class T, class A>
batch<T, A> tgamma(batch<T, A> const& x) {
  return kernel::tgamma<A>(x, A{});
}

/**
 * @ingroup batch_conversion
 *
 * Perform a conversion from \c i to a value of an floating point type of the same size as \c T
 * @param i batch of integers.
 * @return \c i converted to a value of an floating point type of the same size as \c T
 */
template<class T, class A>
batch<as_float_t<T>, A> to_float(batch<T, A> const& i) {
  return kernel::to_float<A>(i, A{});
}

/**
 * @ingroup batch_conversion
 *
 * Perform a conversion from \c x to a value of an integer type of the same size as \c T
 * @param x batch.
 * @return \c x converted to a value of an integer type of the same size as \c T
 */
template<class T, class A>
batch<as_integer_t<T>, A> to_int(batch<T, A> const& x) {
  return kernel::to_int<A>(x, A{});
}

/**
 * @ingroup batch_rounding
 *
 * Computes the batch of nearest integer values not greater in magnitude
 * than scalars in \c x.
 * @param x batch of floating point values.
 * @return the batch of nearest integer values not greater in magnitude than \c x.
 */
template<class T, class A>
batch<T, A> trunc(batch<T, A> const& x) {
  return kernel::trunc<A>(x, A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Unpack and interleave data from the HIGH half of batches \c x and \c y.
 * Store the results in the Return value.
 * @param x a batch of integer or floating point or double precision values.
 * @param y a batch of integer or floating point or double precision values.
 * @return a batch of the high part of shuffled values.
 */
template<class T, class A>
batch<T, A> zip_hi(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::zip_hi<A>(x, y, A{});
}

/**
 * @ingroup batch_data_transfer
 *
 * Unpack and interleave data from the LOW half of batches \c x and \c y.
 * Store the results in the Return value.
 * @param x a batch of integer or floating point or double precision values.
 * @param y a batch of integer or floating point or double precision values.
 * @return a batch of the low part of shuffled values.
 */
template<class T, class A>
batch<T, A> zip_lo(batch<T, A> const& x, batch<T, A> const& y) {
  return kernel::zip_lo<A>(x, y, A{});
}

// bitwise_cast
template <class A, class T, typename std::enable_if<std::is_integral<T>::value, int>::type = 3>
batch<T, A> bitwise_cast(batch_bool<T, A> const& self)
{
  T z(0);
  return select(self, batch<T, A>(T(~z)), batch<T, A>(z));
}
    
template <class A, class T, typename std::enable_if<std::is_floating_point<T>::value, int>::type = 3>
batch<T, A> bitwise_cast(batch_bool<T, A> const& self)
{
    T z0(0), z1(0);
    using int_type = as_unsigned_integer_t<T>;
    int_type value(~int_type(0));
    std::memcpy(&z1, &value, sizeof(int_type));
    return select(self, batch<T, A>(z1), batch<T, A>(z0)); 
}

/**
 * @ingroup batch_bool_reducers
 *
 * Returns true if all the boolean values in the batch are true,
 * false otherwise.
 * @param x the batch to reduce.
 * @return a boolean scalar.
 */
template<class T, class A>
bool all(batch_bool<T, A> const& x) {
  return kernel::all<A>(x, A{});
}

/**
 * @ingroup batch_bool_reducers
 *
 * Return true if any of the boolean values in the batch is true,
 * false otherwise.
 * @param x the batch to reduce.
 * @return a boolean scalar.
 */
template<class T, class A>
bool any(batch_bool<T, A> const& x) {
  return kernel::any<A>(x, A{});
}

/**
 * @ingroup batch_miscellaneous
 *
 * Dump the content of batch \c x to stream \c o
 * @param o the stream where the batch is dumped
 * @param x batch to dump.
 * @return a reference to \c o
 */
template<class T, class A>
std::ostream& operator<<(std::ostream& o, batch<T, A> const& x) {
  constexpr auto size = batch<T, A>::size;
  alignas(A::alignment()) T buffer[size];
  x.store_aligned(&buffer[0]);
  o << '(';
  for(std::size_t i = 0; i < size - 1; ++i)
    o << buffer[i] << ", ";
  return o << buffer[size - 1] << ')';
}
}

#endif

