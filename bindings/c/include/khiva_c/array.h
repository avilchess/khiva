// Copyright (c) 2019 Shapelets.io
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef KHIVA_BINDINGC_ARRAY_H
#define KHIVA_BINDINGC_ARRAY_H

#include <khiva_c/defines.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates an Array object.
 *
 * @param data Data used in order to create the array.
 * @param ndims Number of dimensions of the data.
 * @param dims Cardinality of dimensions of the data.
 * @param result Array created.
 * @param type Data type.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void create_array(const void *data, unsigned ndims, const long long *dims, khiva_array *result, int type,
                              int *error_code, char *error_message);

/**
 * @brief Decreases the references count of the given array.
 *
 * @param array The Array to release.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void delete_array(khiva_array *array, int *error_code, char *error_message);

/**
 * @brief Displays an Array.
 *
 * @param array The array to display.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void display(const khiva_array *array, int *error_code, char *error_message);

/**
 * @brief Retrieves the data from the device to the host.
 *
 * @param array The Array that contains the data to be retrieved.
 * @param data Pointer to previously allocated memory in the host.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void get_data(const khiva_array *array, void *data, int *error_code, char *error_message);

/**
 * @brief Gets the Array dimensions.
 *
 * @param array Array from which to get the dimensions.
 * @param dims The dimensions.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void get_dims(const khiva_array *array, long long *dims, int *error_code, char *error_message);

/**
 * @brief Gets the type of the array.
 *
 * @param array The array to obtain the type information from.
 * @param type Value of the Dtype enumeration.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void get_type(const khiva_array *array, int *t, int *error_code, char *error_message);

/**
 * @brief Joins the first and second arrays along the specified dimension.
 *
 * @param dim The dimension along which the join occurs.
 * @param first The first input array.
 * @param second The second input array.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void join(int dim, const khiva_array *first, const khiva_array *second, khiva_array *result,
                      int *error_code, char *error_message);

/**
 * @brief Adds two arrays.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_add(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                           char *error_message);

/**
 * @brief Multiplies two arrays.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_mul(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                           char *error_message);

/**
 * @brief Subtracts two arrays.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_sub(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                           char *error_message);

/**
 * @brief Divides lhs by rhs (element-wise).
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_div(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                           char *error_message);

/**
 * @brief Performs the modulo operation of lhs by rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_mod(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                           char *error_message);

/**
 * @brief Powers lhs with rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation. Base.
 * @param rhs Right-hand side KHIVA array for the operation. Exponent.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_pow(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                           char *error_message);

/**
 * @brief Compares (element-wise) if lhs is lower than rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_lt(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                          char *error_message);

/**
 * @brief Compares (element-wise) if lhs is greater than rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_gt(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                          char *error_message);

/**
 * @brief Compares (element-wise) if lhs is lower or equal than rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_le(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                          char *error_message);

/**
 * @brief Compares (element-wise) if lhs is greater or equal than rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_ge(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                          char *error_message);

/**
 * @brief Compares (element-wise) if rhs is equal to rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_eq(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                          char *error_message);

/**
 * @brief Compares (element-wise) if lhs is not equal to rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_ne(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                          char *error_message);

/**
 * @brief Performs an AND operation (element-wise) with lhs and rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_bitand(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                              char *error_message);

/**
 * @brief Performs an OR operation (element-wise) with lhs and rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_bitor(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                             char *error_message);

/**
 * @brief Performs an eXclusive-OR operation (element-wise) with lhs and rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_bitxor(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                              char *error_message);

/**
 * @brief Performs a left bit shift operation (element-wise) to array as many times as specified in the parameter n.
 *
 * @param array KHIVA Array to shift.
 * @param n Number of bits to be shifted.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_bitshiftl(const khiva_array *array, int n, khiva_array *result, int *error_code,
                                 char *error_message);

/**
 * @brief Performs a right bit shift operation (element-wise) to array as many times as specified in the parameter n.
 *
 * @param array KHIVA Array to shift.
 * @param n Number of bits to be shifted.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_bitshiftr(const khiva_array *array, int n, khiva_array *result, int *error_code,
                                 char *error_message);

/**
 * @brief Logical NOT operation to array.
 *
 * @param array KHIVA Array to negate.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_not(const khiva_array *array, khiva_array *result, int *error_code, char *error_message);

/**
 * @brief Transposes array.
 *
 * @param array KHIVA Array to transpose.
 * @param conjugate If true a conjugate transposition is performed.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_transpose(const khiva_array *array, bool conjugate, khiva_array *result, int *error_code,
                                 char *error_message);

/**
 * @brief Retrieves a given column of array.
 *
 * @param array KHIVA Array.
 * @param index The column to be retrieved.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_col(const khiva_array *array, int index, khiva_array *result, int *error_code,
                           char *error_message);

/**
 * @brief Retrieves a subset of columns of array, starting at first and finishing at last, both inclusive.
 *
 * @param array KHIVA Array.
 * @param first Start of the subset of columns to be retrieved.
 * @param last End of the subset of columns to be retrieved.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_cols(const khiva_array *array, int first, int last, khiva_array *result, int *error_code,
                            char *error_message);

/**
 * @brief Retrieves a given row of array.
 *
 * @param array KHIVA Array.
 * @param index The row to be retrieved.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_row(const khiva_array *array, int index, khiva_array *result, int *error_code,
                           char *error_message);

/**
 * @brief Retrieves a subset of rows of array, starting at first and finishing at last, both inclusive.
 *
 * @param array KHIVA Array.
 * @param first Start of the subset of rows to be retrieved.
 * @param last End of the subset of rows to be retrieved.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_rows(const khiva_array *array, int first, int last, khiva_array *result, int *error_code,
                            char *error_message);

/**
 * @brief Creates a KHIVA array from an ArrayFire array.
 *
 * @param arrayfire ArrayFire array reference.
 * @param result KHIVA Array.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void from_arrayfire(const khiva_array *arrayfire, khiva_array *result, int *error_code,
                                char *error_message);

/**
 * @brief Performs a matrix multiplication of lhs and rhs.
 *
 * @param lhs Left-hand side KHIVA array for the operation.
 * @param rhs Right-hand side KHIVA array for the operation.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_matmul(const khiva_array *lhs, const khiva_array *rhs, khiva_array *result, int *error_code,
                              char *error_message);
/**
 * @brief Performs a deep copy of array.
 *
 * @param array KHIVA Array.
 * @param result KHIVA Array which contains a copy of array.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void copy(const khiva_array *array, khiva_array *result, int *error_code, char *error_message);
/**
 * @brief Changes the type of array.
 *
 * @param array KHIVA Array.
 * @param type Target type of the output array.
 * @param result KHIVA Array with the result of this operation.
 * @param error_code Allocated pointer to integer, where the resulting error_code is stored.
 * @param error_message Allocated char array to KHIVA_ERROR_LENGTH, where the resulting error message is stored.
 */
KHIVA_C_API void khiva_as(const khiva_array *array, int type, khiva_array *result, int *error_code,
                          char *error_message);

#ifdef __cplusplus
}
#endif

#endif
