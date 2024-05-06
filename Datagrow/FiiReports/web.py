import fitz  # Importa a biblioteca PyMuPDF

def extrair_texto_pdf(input_pdf_path, output_txt_path):
    # Abre o arquivo PDF
    pdf_file = fitz.open(input_pdf_path)

    # Inicializa uma string para armazenar o texto extraído
    texto = ""

    # Itera sobre cada página do PDF
    for page_num in range(len(pdf_file)):
        # Extrai o texto da página atual
        page_text = pdf_file[page_num].get_text()
        texto += page_text  # Concatena o texto extraído

    # Fecha o arquivo PDF
    pdf_file.close()

    # Salva o texto extraído em um arquivo de texto
    with open(output_txt_path, "w", encoding="utf-8") as txt_file:
        txt_file.write(texto)

    print(f"Texto extraído do PDF e salvo em '{output_txt_path}'.")

# Caminhos para o arquivo PDF de entrada e arquivo de texto de saída
input_pdf_path = "202403_Carta_Gestor_VCRA11.pdf"
output_txt_path = "202403_Carta_Gestor_VCRA11.txt"

# Chama a função para extrair texto do PDF e salvar como arquivo de texto
extrair_texto_pdf(input_pdf_path, output_txt_path)
