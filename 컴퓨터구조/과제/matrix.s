.text
.global matrix

matrix:
	stmfd sp!, {r0-r12,lr} // 사용할 레지스터 스택영역에 push

	ldr r4, [r3, #4] // u 값을 r4에 로드
	ldr r5, [r3, #8] // v 값을 r3에 로드
	ldr r10, [r3, #0] // s 값을 r10에 로드
	mov r6,#0 // s까지의 인덱스
	mov r7,#0 // u까지의 인덱스
	mov r8,#0 // v까지의 인덱스
	mov r9,#0 // 곱연산을 저장함
Loop:
	mov r11, r0 // A의 원소를 저장할 레지스터
	ldr r11, [r11, r6, lsl#2]

	ldr r11, [r11, r7, lsl#2] // r6, r7 인덱스에 대한 값을 r11에 로드
	
	mov r12, r1 // B의 원소를 저장할 레지스터
	ldr r12, [r12, r7, lsl#2]

	ldr r12, [r12, r8, lsl#2] // r7, r8 인덱스에 대한 값을 r12에 로드

	mul r12, r11, r12 // A와 B의 원소를 곱해 r12에 저장
	add r9, r9, r12 // 곱한 값을 r9에 누적시킴

	add r7, r7, #1 // r7 인덱스를 증가시킴
	cmp r7, r4
	bne Loop // 인덱스값이 u와 같을 때 까지 반복
	mov r7, #0 // r7에 0을 저장

	mov r11, r2 // C의 원소를 저장할 레지스터
	ldr r11, [r11, r6, lsl#2]

	add r11, r11, r8, lsl#2 // r6, r8 인덱스에 대한 값을 r11에 지정

	str r9, [r11] // 연산이 끝난 r9을 r11위치에 저장

	mov r9, #0 // r9 초기화

	add r8,r8,#1 // r8 인덱스 증가
	cmp r8, r5
	bne Loop // 인덱스값이 v와 같을 때 까지 반복

	mov r8,#0 // r8 인덱스 초기화

	add r6,r6,#1 // r6 인덱스 증가
	cmp r6,r10
	bne Loop // 인덱스값이 s와 같을 때 까지 반복

	ldmfd sp!, {r0-r12,pc} // 사용한 레지스터 스택에서 pop, 함수 호출 이전으로 되돌림
.end
