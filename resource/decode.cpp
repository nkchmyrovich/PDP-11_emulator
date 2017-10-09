#include <stdint.h>
#include "decode.h"
#include <stdio.h>

decode_op_t decode_table[2] =
{
	{0xffff,  0xffff, mov},
	{NULL, NULL, nullptr}
};

Decoder::Decoder()
{

}

Decoder::~Decoder()
{

}

bool Decoder::decodeAndExecute(Vcpu* vcpu, opcode_t opcode)
{
	int i = 0;

	while (decode_table[i].execute != nullptr)
	{
		if (decode_table[i].mask && opcode.value == decode_table[i].value)
		{
			return decode_table[i].execute(vcpu, opcode);
		}
	}

	return false;
}

bool mov(Vcpu *vcpu, opcode_t opcode)
{
	printf("It was mov\n");

	return true;
}