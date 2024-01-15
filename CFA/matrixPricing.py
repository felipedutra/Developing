import numpy as np

def interpolacao_polinomial_lagrange(x, y, pontos_interpolados):
    """
    Realiza a interpolação polinomial de Lagrange para encontrar valores interpolados.
    
    Parâmetros:
    - x: Lista com as coordenadas x dos pontos conhecidos.
    - y: Lista com as coordenadas y dos pontos conhecidos.
    - pontos_interpolados: Lista de pontos para os quais deseja-se interpolar o valor de y.
    
    Retorna:
    - Lista de valores interpolados correspondentes aos pontos dados.
    """
    n = len(x)
    resultado_interpolado = []

    for ponto_interpolado in pontos_interpolados:
        valor_interpolado = 0.0
        for i in range(n):
            termo = y[i]
            for j in range(n):
                if j != i:
                    termo = termo * (ponto_interpolado - x[j]) / (x[i] - x[j])
            valor_interpolado += termo

        resultado_interpolado.append(valor_interpolado)

    return resultado_interpolado

# Exemplo de uso:
# Suponha que você tenha os seguintes pontos (x, y)
pontos_x = np.array([2, 2, 2, 3, 5])
pontos_y = np.array([3.786, 3.821, None, 4.20])

# Preenchendo os valores ausentes usando interpolação
pontos_interpolados = [3, 4, 6, 7.5, 8.5]
valores_interpolados = interpolacao_polinomial_lagrange(pontos_x, pontos_y, pontos_interpolados)

# Exibindo os resultados
for ponto, valor_interpolado in zip(pontos_interpolados, valores_interpolados):
    print(f"Para x = {ponto}, y ≈ {valor_interpolado}")
