		org	0h

		mov		R1, 20h
		mov		R2, 21h
		mov		R3, 22h
		mov		R4, #12h
		mov		R5, #0ABh
		mov		A, R1
		add		A, R2
		mov		B, R3
		mul		AB
		mov		30h, A
		mov		31h, B

Loop:
		jmp		Loop

		end