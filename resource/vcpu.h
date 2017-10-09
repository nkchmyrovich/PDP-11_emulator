#pragma once

class Vcpu
{
	public:
		Vcpu();
		~Vcpu();
	private:
		uint16_t reg0;
		uint16_t reg1;
		uint16_t reg2;
		uint16_t reg3;
		uint16_t reg4;
		uint16_t reg5;
		uint16_t reg6;
		uint16_t reg7;
};