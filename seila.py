def insere(lista, elemento):
    indice = len(lista) - 1 # Seria 9 
    
    while indice >= 0 and lista[indice] > elemento: # indice = 9  # Elemento é 55, indice 35
        lista[indice + 1] = lista[indice] 
        indice -= 1
    
    lista[indice + 1] = elemento


minha_lista = [1, 3, 5, 7, 9]
insere(minha_lista, 4)
print(minha_lista)  # Saída: [1, 3, 4, 5, 7, 9]
