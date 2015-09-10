;define control registers (with address)
XBR2			equ		0e3h
P1MDIN			equ		0adh
P2MDOUT			equ		0a6h
WDTCN			equ		0ffh
SFRPAGE			equ		084h
P1				equ		090h
P2				equ		0a0h

;define control words
CONFIG_PAGE		equ		0fh
LEGACY_PAGE		equ		00h

				;turn-off the watch-dog timer
				mov		WDTCN, #0deh
				mov		WDTCN, #0adh

				;setup port configuration
				mov		SFRPAGE, #CONFIG_PAGE
				mov		XBR2, #0c0h
				mov		P1MDIN, #0ffh
				mov		P2MDOUT, #0ffh
				mov		SFRPAGE, #LEGACY_PAGE

				mov		R0, #0

				;detect button and display
Loop_Begin:
				mov		R0, P1
				mov		P2, R0
				sjmp	Loop_Begin

				end
