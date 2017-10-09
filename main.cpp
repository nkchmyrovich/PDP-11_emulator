#include <stdio.h>
#include <stdint.h>
#include "resource/decode.h"
#include "resource/vcpu.h"


int main()
{
	printf("R1\n");
	
	int a;
	scanf_s("%d", &a);

	opcode_t opcode = { a };

	Vcpu vcpu = Vcpu();
	Decoder decoder = Decoder();
	decoder.decodeAndExecute(&vcpu, opcode);


	return 0;
}

