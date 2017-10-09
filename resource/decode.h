#pragma once
#include "vcpu.h"

struct exec_status_t
{
	bool status;
};

struct opcode_t
{
	uint16_t value;
};

struct decode_op_t
{
	uint16_t mask;
	uint16_t value;
	bool(*execute) (Vcpu *vcpu, opcode_t opcode);
};

class Decoder
{
	public:
		Decoder();
		~Decoder();

		bool decodeAndExecute(Vcpu* vcpu, opcode_t opcode);
	private:
};

bool mov(Vcpu *vcpu, opcode_t opcode);