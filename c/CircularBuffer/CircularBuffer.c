/**
 * @file  CircularBuffer.c
 * @brief Implementation of module CircularBuffer.
 */

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Includes
 * ---------------------------------------------------------------------------------------------------------------------
 */

#include "CircularBuffer.h"

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
 * ---------------------------------------------------------------------------------------------------------------------
 * Prototypes
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * @brief     Get number of bytes until either write pointer or end of buffer.
 *
 * @param     pCircularBuffer[in] Pointer to CircularBuffer struct to use.
 *
 * @return
 *      - Number of bytes until end.
 */
size_t CircularBuffer_BytesUntilEnd( CircularBuffer_t *pCircularBuffer );

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Variables
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Interface functions
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * *********************************************************************************************************************
 * Function
 * *********************************************************************************************************************
 */
bool ICircularBuffer_Init( CircularBuffer_t *pCircularBuffer, uint8_t *pBuffer, size_t bufferSize )
{
    if ( pCircularBuffer == NULL || pBuffer == NULL )
    {
        // NULL pointers not accepted
        return false;
    }

    if ( bufferSize < 2 || ( ( bufferSize & ~( bufferSize - 1 ) ) != bufferSize ) )
    {
        // bufferSize is 0 or not power of 2
        return false;
    }

    pCircularBuffer->bufferSize = bufferSize;
    pCircularBuffer->pBuffer    = pBuffer;
    pCircularBuffer->pWrite     = pBuffer;
    pCircularBuffer->pRead      = pBuffer;

    return true;
}

/**
 * *********************************************************************************************************************
 * Function
 * *********************************************************************************************************************
 */
size_t ICircularBuffer_GetCount( CircularBuffer_t *pCircularBuffer )
{
    if ( pCircularBuffer == NULL )
    {
        return 0;
    }

    size_t count = 0;
    if ( pCircularBuffer->pWrite >= pCircularBuffer->pRead )
    {
        count = ( pCircularBuffer->pRead - pCircularBuffer->pWrite );
    }
    else
    {
        // Remaining from read pointer to end of data buffer
        count = ( ( pCircularBuffer->pBuffer + pCircularBuffer->bufferSize ) - pCircularBuffer->pRead );
        // Add bytes from start of databuffer to write pointer
        count += ( pCircularBuffer->pWrite - pCircularBuffer->pBuffer );
    }

    return count;
}

/**
 * *********************************************************************************************************************
 * Function
 * *********************************************************************************************************************
 */
size_t ICircularBuffer_Peek( CircularBuffer_t *pCircularBuffer, uint8_t const **ppData )
{
    if ( pCircularBuffer == NULL || ppData == NULL )
    {
        return 0;
    }

    size_t bytesToEnd = CircularBuffer_BytesUntilEnd( pCircularBuffer );
    if ( bytesToEnd > 0 )
    {
        *ppData = pCircularBuffer->pRead;
    }

    return bytesToEnd;
}

/**
 * *********************************************************************************************************************
 * Function
 * *********************************************************************************************************************
 */
size_t ICircularBuffer_Pop( CircularBuffer_t *pCircularBuffer, uint8_t *pData, size_t count  )
{
    // TODO: Implement me
    return 0;
}

/**
 * *********************************************************************************************************************
 * Function
 * *********************************************************************************************************************
 */
size_t ICircularBuffer_Push( CircularBuffer_t *pCircularBuffer, uint8_t *pData, size_t count  )
{
    // TODO: Implement me
    return 0;
}

/**
 * *********************************************************************************************************************
 * Function
 * *********************************************************************************************************************
 */
bool ICircularBuffer_Clear( CircularBuffer_t *pCircularBuffer )
{
    // TODO: Implement me
    return false;
}

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Private functions
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * *********************************************************************************************************************
 * Function
 * *********************************************************************************************************************
 */
size_t CircularBuffer_BytesUntilEnd( CircularBuffer_t *pCircularBuffer )
{
    // TODO: Use SOFTWARE_EXCEPTION, assert or alike instead... This is an internal function and should never get NULL.
    if ( pCircularBuffer == NULL )
    {
        return 0;
    }

    size_t count = 0;
    if ( pCircularBuffer->pRead < pCircularBuffer->pWrite )
    {   // Count up to write pointer
        count = ( pCircularBuffer->pWrite - pCircularBuffer->pRead );
    }
    else
    {   // Count to end of data buffer
        count = ( ( pCircularBuffer->pBuffer + pCircularBuffer->bufferSize ) - pCircularBuffer->pRead );
    }

    return count;
}