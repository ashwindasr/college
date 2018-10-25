ASSUME CS:CODE,DS:DATA
DATA SEGMENT
  num db 05h
DATA ENDS
CODE SEGMENT
START: MOV AX,DATA
       MOV DS,AX
       MOV BL,num
       MOV CL,00H
  L:   
       MOV AL,CL
       MUL AL
       CMP AL,BL
       JE ANS
       INC CL
       CMP AL,BL
       JL L

       MOV AH,4CH
       INT 21H

 ANS:  MOV DL,CL
       MOV AH,4CH
       INT 21H
CODE ENDS
END START
