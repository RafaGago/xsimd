#ifndef XSIMD_REGISTER_HPP
#define XSIMD_REGISTER_HPP

#include <type_traits>

namespace xsimd
{

    template<class T, class A>
    struct batch;

    template<class T, class A>
    struct batch_bool;

    namespace types
    {

        template<class T, class Arch>
        struct simd_register;

        template <class T, class A>
        struct has_simd_register : std::false_type
        {
        };

#define XSIMD_DECLARE_SIMD_REGISTER(SCALAR_TYPE, ISA, VECTOR_TYPE) \
    template<> \
    struct simd_register<SCALAR_TYPE, ISA>\
    {\
        using register_type = VECTOR_TYPE;\
        register_type data;\
        operator register_type() const { return data; }\
    };\
    template <>\
    struct has_simd_register<SCALAR_TYPE, ISA> : std::true_type\
    {}

#define XSIMD_DECLARE_SIMD_REGISTER_ALIAS(ISA, ISA_BASE)\
    template<class T> \
    struct simd_register<T, ISA> : simd_register<T, ISA_BASE>\
    {\
        using register_type = typename simd_register<T, ISA_BASE>::register_type;\
        simd_register(register_type reg) : simd_register<T, ISA_BASE>{reg} {}\
        simd_register() = default;\
    };\
    template<class T>\
    struct has_simd_register<T, ISA> : has_simd_register<T, ISA_BASE>\
    {}

        template <class T, class Arch>
        struct get_bool_simd_register
        {
            using type = simd_register<T, Arch>;
        };

        template <class T, class Arch>
        using get_bool_simd_register_t = typename get_bool_simd_register<T, Arch>::type;
    }

    namespace kernel
    {
        // TODO: rename this, as it might conflict with C++20 keyword.
        // We should use add_const and add_reference to build A const&
        template<class A>
        using requires_arch = A const&;
        template<class T>
        struct convert {};
    }
}

#endif
