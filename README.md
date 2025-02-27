# Filtro de Mediana e Arquivo PGM


Trabalho de Algoritmos  |  27/02/2025

  # Introdução ao Problema

No mundo digital, imagens podem ser corrompidas por diversos tipos de ruídos, tornando sua qualidade inferior e dificultando sua interpretação. Um dos métodos mais eficazes para reduzir esses problemas é o Filtro de Mediana, uma técnica de processamento de imagens que substitui cada pixel por um valor representativo da vizinhança, preservando bordas e texturas importantes.

 # Importância do Filtro de Mediana

O Filtro de Mediana é amplamente utilizado em áreas como medicina, segurança e reconhecimento de padrões. Sua principal vantagem em relação a outros filtros, como o Filtro da Média, é sua capacidade de reduzir ruídos sem borrar a imagem, garantindo a manutenção de detalhes importantes. Essa característica o torna uma ferramenta fundamental para aprimorar a qualidade de imagens degradadas por ruídos impulsivos, como pixels defeituosos em fotos digitais.

# Desafios na Implementação

Durante o desenvolvimento do código, enfrentamos diversos desafios, como a necessidade de manipular arquivos no formato PGM (Portable Gray Map), um formato simples, porém exigente, que armazena imagens em tons de cinza. Além disso, foi necessário implementar a lógica para lidar com pixels ausentes e calcular corretamente a mediana dos vizinhos. Um dos principais problemas encontrados foi a dificuldade em decodificar a imagem corretamente e lidar com o ruído nos arquivos do tipo P2, que exigiu um tratamento especial na leitura e processamento dos dados.

# Implementação do Filtro de Mediana no Código

O código desenvolvido aplica o Filtro de Mediana para corrigir pixels corrompidos dentro de uma janela de 3x3. A implementação segue os seguintes passos:

1. Leitura da Imagem: A função readPGM carrega a imagem no formato PGM, identificando pixels ausentes e preparando os dados para o processamento.
2. Aplicação do Filtro de Mediana: A função fixImage percorre a matriz da imagem, coletando os valores dos vizinhos de cada pixel ausente, ordenando-os e substituindo pelo valor mediano.
3. Salvamento da Imagem Corrigida: Após o processamento, a função savePGM grava a imagem corrigida em um novo arquivo PGM.
4. Exibição da Imagem: Para visualizar o resultado, a função printImage exibe a matriz processada no console.

Essa abordagem permitiu que a imagem fosse restaurada com sucesso, reduzindo significativamente os ruídos e preservando a integridade dos detalhes.

 # Conclusão

O Filtro de Mediana se mostrou uma solução eficiente para a remoção de ruídos em imagens, demonstrando sua importância no processamento digital. Apesar dos desafios na manipulação do formato PGM, conseguimos implementar um algoritmo funcional, reforçando a relevância dos conceitos de ordenação e análise de vizinhança em problemas computacionais. Essa experiência proporcionou um aprendizado valioso sobre o tratamento e melhoria da qualidade de imagens digitais.

**Integrantes do grupo:**

[Ana Clara Gastão](https://github.com/clara-lazz), [Victoria Luize Ortiz](), [Giovanna Rodrigues Cordeiro](https://github.com/giovanna-cordeiro/giovanna-cordeiro), e Débora Ramalho Robles
