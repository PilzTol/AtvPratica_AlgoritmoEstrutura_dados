		cerr << "Testando empilha() [overflow]: ";
		pilha.empilha(MAX + 1);
		if (pilha.tamanho() > MAX)
		{
			cerr << "OK (Estouro da pilha)" << endl;
			exit(1);
		}
		else
		{
		cerr << "FALHOU!" << endl;
		exit(1);
		}