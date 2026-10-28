
#include <stdio.h>
#include <stdint.h>

#define SIZE 8

uint8_t buffer[SIZE];
uint8_t head = 0;
uint8_t tail = 0;
uint8_t count = 0;

int is_full(void)
{
    return count == SIZE;
}

int is_empty(void)
{
    return count == 0;
}

int write_byte(uint8_t value)
{
    if (is_full())
    {
        return 0;
    }

    buffer[head] = value;
    head = (head + 1) % SIZE;
    count++;

    return 1;
}

int read_byte(uint8_t *value)
{
    if (is_empty())
    {
        return 0;
    }

    *value = buffer[tail];
    tail = (tail + 1) % SIZE;
    count--;

    return 1;
}

int main(void)
{
    uint8_t value;
    int i;

    for (i = 0; i < SIZE; i++)
    {
        write_byte(0x41 + i);
    }

    printf("Count = %u\n", (unsigned int)count);
    printf("Full = %d\n\n", is_full());

    if (write_byte(0x99) == 0)
    {
        printf("Write failed: buffer full\n\n");
    }

    printf("Reading 3 bytes:\n");

    for (i = 0; i < 3; i++)
    {
        if (read_byte(&value))
        {
            printf("Read = 0x%02X\n", (unsigned int)value);
        }
    }

    printf("Count = %u\n\n", (unsigned int)count);

    printf("Writing 3 new bytes:\n");

    for (i = 0; i < 3; i++)
    {
        write_byte(0x49 + i);
    }

    printf("Count = %u\n\n", (unsigned int)count);

    printf("Reading remaining bytes:\n");

    while (!is_empty())
    {
        read_byte(&value);
        printf("Read = 0x%02X\n", (unsigned int)value);
    }

    printf("Count = %u\n", (unsigned int)count);
    printf("Empty = %d\n\n", is_empty());

    if (read_byte(&value) == 0)
    {
        printf("Read failed: buffer empty\n");
    }

    return 0;
}
