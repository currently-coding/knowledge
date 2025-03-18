import pdfplumber


def extract_definitions(pdf_path, output_path):
    formatted_definitions = []

    # Open the PDF file
    with pdfplumber.open(pdf_path) as pdf:
        for page in pdf.pages:
            text = page.extract_text()
            print(text)

            if text:
                # Split the text into lines and search for key patterns
                lines = text.split("\n")
                for line in lines:
                    if line.strip():
                        # Check for table entries and definitions
                        if "Definition" in line or any(
                            word in line
                            for word in [
                                "Quellen",
                                "Altsteinzeit",
                                "Jungsteinzeit",
                                "Pharao",
                            ]
                        ):  # Add other keywords as needed
                            title = line.strip()
                            formatted_definitions.append(
                                f"**{title}**\n?\n>[!Definition]\n<Add your extracted content here>\n"
                            )

    # Write the formatted content to a file
    with open(output_path, "w", encoding="utf-8") as output_file:
        output_file.write("\n\n".join(formatted_definitions))


# Define the paths
pdf_file_path = "Geschichte\\Grundlegende Daten und Begriffe\\GDB_Geschichte_LPP_Oberstufe_31.03.2023.pdf"
output_file_path = "Geschichte\\Grundelegende Daten und Begriffe\\all.md"

# Extract and save the data
extract_definitions(pdf_file_path, output_file_path)
