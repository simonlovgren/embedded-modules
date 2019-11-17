/**
 * @file      ICircularBuffer.h
 * @brief     Interface header for module CircularBuffer.
 *
 * @version   0.0.1
 * @date      2019
 *
 * @author    Simon Lövgren
 * @copyright MIT License
 */

#ifndef ICIRCULARBUFFER_H
#define ICIRCULARBUFFER_H

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Includes
 * ---------------------------------------------------------------------------------------------------------------------
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Types
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * Circular buffer
 * @warning Never access any members of the struct, for internal use only.
 */
typedef struct CircularBuffer
{
    uint8_t *pWrite;    /**< Pointer to where in buffer writer should write to.  */
    uint8_t *pRead;     /**< Pointer to where in buffer reader should read from. */
    uint8_t *pBuffer;   /**< Pointer to allocated buffer.                        */
    size_t  bufferSize; /**< Size of buffer.                                     */
} CircularBuffer_t;

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Prototypes
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * @brief     Initialize a circular buffer.
 *
 * @attention Buffer size is only valid if a power of 2 (64, 28, 256, 512, 1024, etc.).
 *
 * @param     pCircularBuffer[in] Pointer to CircularBuffer struct to initialize.
 * @param     pBuffer[in]         Pointer to allocated data buffer.
 * @param     bufferSize[in]      Size of allocated data buffer.
 *
 * @return
 *      - true:  Success.
 *      - false: Failed.
 */
bool ICircularBuffer_Init( CircularBuffer_t *pCircularBuffer, uint8_t *pBuffer, size_t bufferSize );

/**
 * @brief     Get number of bytes available to read from buffer.
 *
 * @param     pCircularBuffer[in] Pointer to CircularBuffer struct to use.
 *
 * @return
 *      - Number of bytes available for reading.
 */
size_t ICircularBuffer_GetCount( CircularBuffer_t *pCircularBuffer );

/**
 * @brief     Peek at data in buffer without removing it.
 *
 * @attention Peek does not wrap around the end of the buffer memory. It will return at most the number of bytes
 *            until the end of the buffer memory.
 *
 * @param     pCircularBuffer[in] Pointer to CircularBuffer struct to use.
 * @param     pData[out]          Pointer to where to start peek.
 *
 * @return
 *      - Number of bytes possible to peek at.
 */
size_t ICircularBuffer_Peek( CircularBuffer_t *pCircularBuffer, uint8_t const **ppData );

/**
 * @brief     Pop data from circular buffer.
 *
 * @attention This will remove the data from the circular buffer.
 *
 * @param     pCircularBuffer[in] Pointer to CircularBuffer struct to use.
 * @param     pData[out]          Where data is to be copied to.
 * @param     count[in]           Number of bytes to pop.
 *
 * @return
 *      - Number of bytes copied/popped.
 */
size_t ICircularBuffer_Pop( CircularBuffer_t *pCircularBuffer, uint8_t *pData, size_t count  );

/**
 * @brief     Push data to circular buffer.
 *
 * @param     pCircularBuffer[in] Pointer to CircularBuffer struct to use.
 * @param     pData[out]          Where data is to be copied from.
 * @param     count[in]           Number of bytes to push.
 *
 * @return
 *      - Number of bytes copied/pushed.
 */
size_t ICircularBuffer_Push( CircularBuffer_t *pCircularBuffer, uint8_t *pData, size_t count  );

/**
 * @brief     Clear circular buffer.
 *
 * @param     pCircularBuffer[in] Pointer to CircularBuffer struct to clear.
 *
 * @return
 *      - true:  Succesful.
 *      - false: Failed.
 */
bool ICircularBuffer_Clear( CircularBuffer_t *pCircularBuffer );

#endif  // ICIRCULARBUFFER_H