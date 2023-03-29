# GnomeSort

  O Gnome Sort é um algoritmo de ordenação que busca ordenar elementos que estejam desordenados, ele percorre um vetor seja de strings ou de números para comparar, se o elemento atual vier depois, troca a posição, caso contrário, permanece no lugar.

##

# Execução

  Para executar esse código o usuário pode digitar no terminal “gcc main.c -o main” dar enter e digitar “./main”, tanto para linux quanto para windows. Depois de realizar esses dois passos o programa irá compilar pedindo ao usuário para digitar se ele quer abrir um arquivo para inserir os alunos, logo após pede o nome do aluno, a matrícula, qual documento o usuário deseja inserir, e pede o número desse documento, e ordena no arquivo em ordem alfabética.

# Complexidade

  O Gnome Sort tem uma complexidade O(n²), n é o número de elementos que vão ser ordenados, por isso que o tempo de execução pode ser um pouco lento, dependendo da ordenação a ser feita. No pior caso cada elemento precisa ser comparado com todos os elementos anteriores para alcançar sua posição correta, que seria n*(n-1). Já no melhor caso ele tem uma complexidade O(n), que é quando o vetor já está ordenado e não precisa fazer troca de posições.
