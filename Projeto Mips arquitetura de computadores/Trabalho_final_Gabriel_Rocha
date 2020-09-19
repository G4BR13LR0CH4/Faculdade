.data
	msg0: .asciiz "\nBiometria: \n 0.Desativada\n 1.Ativada\n"
	msg1: .asciiz "\nDigite o valor da compra:"
	msg2: .asciiz "\nDigite o numero do cartão:"
	msg3: .asciiz "\nDigite a senha: "
	msg4: .asciiz "\n\nCompra efetuada com sucesso!"
	msg5: .asciiz "\nValor da compra: "
	msg6: .asciiz "\nNumero do cartão: "
	msg7: .asciiz "\nCOMPRA NEGADA!"
	msg8: .asciiz "\nDigite o saldo disponivel no cartão: "
	msg9: .asciiz "\nSaldo restante: "
	
	valor_limite: .float 1000.0 #define o valor maximo aceito da compra
	numc: .space 17 #armazena o numero do cartão:
	nums: .space 5 #armazena a senha:
	
.text
		#solicita o Saldo disponivel no cartão:
	li $v0, 4 #li carrega o valor 4 para $v0
	la $a0, msg8 #la carrega o valor de msg8 na memoria:
	syscall#syscall faz a chamada de sistema que permite utilizar 4 como uma chave
			#de comando e imprimir uma string na tela
	li $v0, 6 #li está carregando o valor 6 para $v0, 6 que para o sistema siginifica
			#leitura de um numero float
	syscall
	mov.s $f3, $f0 #move.s move um valor float sem dupla precisão, esse valor que
		#é armazenado por padrão em $f0, está sendo passado para outro registrador:
	
	#passo 1: Leitura biometrica
	li $v0, 4 #imprime mensagem na tela
	la $a0, msg0 #exibição de uma string
	syscall 
	
		#leitura de inteiro:
	li $v0, 5 #li carrega o valor 5 para $v0, para o sistema o valor 5 significa
			#leitura de inteiros
	syscall
	move $t0, $v0 #comando move está movendo o conteudo de $v0 para guardar em $t0
	
	beqz  $t0, compra_negada #primeiro teste condicional, beqz, ele checa o valor de
		#$t0, e considera tudo que é diferente de zero como falso, e logo em seguida
		#da jump para um label caso seja considerado verdadeiro.
	
	#passo 2: Leitura do valor da compra
	li $v0, 4 #imprime mensagem na tela
	la $a0, msg1#carrega o valor de msg1 para ser impresso(valor que irá para $a0)
	syscall

	li $v0, 6#leitura do valor da compra, leitura de um valor de ponto flutuante
	syscall
	
	l.s $f2, valor_limite #o l.s permite move o valor de uma variavel para um
		#registrador.
	c.le.s $f0, $f2 #o c.le.s compara valores menores ou iguais, ele compara e
		#lança uma especie de flag que é usada na proxima instrução;

	bc1f compra_negada #o bc1f recebe a flag do c.le.s e caso seja verdadeira da 
		#jump no codigo e leva até o label COMPRA_NEGADA

	#teste do saldo
	c.le.s $f0, $f3
			#Mesma coisa que ocorreu em cima.
	bc1f compra_negada
	#3 ler os dados do cartao
	li $v0, 4	# imprime mensagem na tela
	la $a0, msg2 # impressão de uma string
	syscall # chamada de sistema
	
	li $v0, 8 #$v0 com o argumento 8, é possivel ler strings(pelo tamanho do numero
		#optei por fazer uso de strings)
	la $a0, numc #o espaço de numc é passado para $a0
	li $a1, 17 #$a1 limita o tamanho da string:
	syscall
	#Lê senha
	li $v0, 4 #imprime mensagem na tela
	la $a0, msg3
	syscall
	
	li $v0, 8 #leitura de uma string
	la $a0, nums
	li $a1, 5 #limitador do tamanho da string
	syscall
	
	#FIM
	li $v0, 4 #por $v0 está com 4, nessa parte evitarei de coloca-lo repetidamente
	la $a0, msg4 
	syscall
	
	la $a0, msg6
	syscall
	
	la $a0, numc
	li $a1, 17
	syscall
	
	la $a0, msg5
	syscall
	
	li $v0, 2
	mov.s $f12, $f0 #move.s move um float, nesse caso ele está movendo $f0 para $f12
		#pois $f12 é um registrador padrão de exibição de floats
	syscall
	
	sub.s $f3, $f3,$f0 #sub.s subtração de floats, subtrais os valores de $f3 e $f0
		#e armazena em $f3
	li $v0, 4
	la $a0, msg9
	syscall
	
	li $v0, 2
	mov.s $f12, $f3
	syscall
	
	li $v0, 10#encerramento do processo.
	syscall
	
	#compra negada
compra_negada: #label criado para guiar a ação de compra negada.
	li $v0, 4
	la $a0, msg7
	syscall