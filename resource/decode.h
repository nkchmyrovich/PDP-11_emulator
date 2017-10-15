#pragma once
#include "vcpu.h"
#include <iostream>

enum INSTR_TYPE
{
	SINGLE_OPERAND,
	CONDITIONAL,
	DOUBLE_OPERAND_REG,
	DOUBLE_OPERAND,
	UNDEFINED
};

struct exec_status_t
{
	bool status;
};

struct args_t
{
	INSTR_TYPE instrType = UNDEFINED;
	
	uint16_t mode1 = 0;
	uint16_t arg1 = 0;
	uint16_t mode2 = 0;
	uint16_t arg2 = 0;
};

struct opcode_t
{
	uint16_t value;
};

struct decode_op_t
{
	uint16_t mask;
	uint16_t value;
	bool(*execute) (Vcpu *vcpu, opcode_t opcode, args_t args);
	std::string op_name;
};

class Decoder
{
	public:
		Decoder();
		~Decoder();

		args_t defineArguments(uint16_t instr);
		bool decodeAndExecute(Vcpu* vcpu, opcode_t opcode, args_t args);
	private:
};

//double-operand instruction test
bool mov(Vcpu *vcpu, opcode_t opcode, args_t args);
bool movb(Vcpu *vcpu, opcode_t opcode, args_t args);
bool cmp(Vcpu *vcpu, opcode_t opcode, args_t args);
bool cmpb(Vcpu *vcpu, opcode_t opcode, args_t args);
bool bit(Vcpu *vcpu, opcode_t opcode, args_t args);
bool bitb(Vcpu *vcpu, opcode_t opcode, args_t args);
bool bic(Vcpu *vcpu, opcode_t opcode, args_t args);
bool bicb(Vcpu *vcpu, opcode_t opcode, args_t args);
bool bis(Vcpu *vcpu, opcode_t opcode, args_t args);
bool bisb(Vcpu *vcpu, opcode_t opcode, args_t args);
bool add(Vcpu *vcpu, opcode_t opcode, args_t args);
bool sub(Vcpu *vcpu, opcode_t opcode, args_t args);