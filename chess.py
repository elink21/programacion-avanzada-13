#Movimientos posibles para el caballo
horseMoves=[[1,2],[2,1],[-1,-2],[-2,-1],[-1,2],[1,-2],[-2,1],[2,-1]]

#Lambda que verifica que sea un movimiento valido
isValidPath=lambda board,x,y: x in range(len(board)) and y in range(len(board)) and not board[x][y]

#Funcion que devuelve posibles movimientos a realizar
def possibleMoves(board,pos):
	newPositions=[]
	for move in horseMoves:
		newX=pos[0]+move[0]
		newY=pos[1]+move[1]
		if isValidPath(board,newX,newY):
			newPositions.append([newX,newY])
	return newPositions

#Funcion que determinara el mejor movimiento dependiendo de los pesos
def bestOption(board,candidates):
	weights=[]
	for i in range(len(candidates)): weights.append(0)
	for i in range(len(candidates)):
		weights[i]=len ( possibleMoves(board,candidates[i]) )
	minIndex=-1
	minim=1e9
	for i in range(len(candidates)):
		if weights[i]<minim:
			minIndex,minim=i,weights[i]
	return candidates[minIndex]

#Inicializacion del tablero de ajedrez
board=[]
for i in range(8):
	row=[]
	for j in range(8): row.append(0)
	board.append(row)

#Recorrido del tablero
pos=[0,0]
step=1
board[0][0]=step
while step!=64:	
	board[pos[0]][pos[1]]=step
	step+=1
	candidates=possibleMoves(board,pos)
	pos=bestOption(board,candidates)
for row in board: print row
