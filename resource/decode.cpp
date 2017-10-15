#include <stdint.h>
#include <stdio.h>
#include <string>
#include "decode.h"

decode_op_t decode_table[] =
{
	{ 0xf000,  0x1000, mov,		"mov"	},
	{ 0xf000,  0x9000, movb,	"movb"	},
	{ 0xf000,  0x2000, cmp,		"cmp"	},
	{ 0xf000,  0xa000, cmpb,	"cmpb"	},
	{ 0xf000,  0x3000, bit,		"bit"	},
	{ 0xf000,  0xb000, bitb,	"bitb"	},
	{ 0xf000,  0x4000, bic,		"bic"	},
	{ 0xf000,  0xc000, bicb,	"bicb"	},
	{ 0xf000,  0x5000, bis,		"bis"	},
	{ 0xf000,  0xd000, bisb,	"bisb"	},
	{ 0xf000,  0x6000, add,		"add"	},
	{ 0xf000,  0xe000, sub,		"sub"	},
	{ NULL,	   NULL,   nullptr,	"none"	}
};

Decoder::Decoder()
{

}

Decoder::~Decoder()
{

}

args_t Decoder::defineArguments(uint16_t instr)
{
	args_t args;
	
	if ((instr & 0x7800) == 0x0800)
	{
		args.instrType = SINGLE_OPERAND;
		args.mode1 = (instr & 0x0038) >> 3;
		args.arg1  = (instr & 0x0007);
	}
	else if ((instr & 0x7800) == 0x0000)
	{
		args.instrType = CONDITIONAL;
		args.arg1 = (instr & 0x00FF);
	} 
	else if ((instr & 0xF000) == 7000)
	{
		args.instrType = DOUBLE_OPERAND_REG;
		args.arg1 = (instr & 0x00E0) >> 6;
		args.mode2 = (instr & 0x0038) >> 3;
		args.arg2 = (instr & 0x0007);
	}
	else
	{
		args.instrType = DOUBLE_OPERAND;
		args.mode1 = (instr & 0x0700) >> 9;
		args.arg1 = (instr & 0x00E0) >> 6;
		args.mode2 = (instr & 0x0038) >> 3;
		args.arg2 = (instr & 0x0007);
	}

	return args;
}

bool Decoder::decodeAndExecute(Vcpu* vcpu, opcode_t opcode, args_t args)
{
	int i = 0;

	while (decode_table[i].execute != nullptr)
	{
		if ((decode_table[i].mask & opcode.value) == decode_table[i].value)
		{
			std::cout << decode_table[i].op_name << std::endl;
			return decode_table[i].execute(vcpu, opcode, args);
		}

		i++;
	}

	return false;
}

bool mov(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool movb(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool cmp(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool cmpb(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool bit(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool bitb(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool bic(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool bicb(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool bis(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool bisb(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool add(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}

bool sub(Vcpu *vcpu, opcode_t opcode, args_t args)
{
	return true;
}