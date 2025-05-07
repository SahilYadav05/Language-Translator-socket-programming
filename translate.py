import sys
from googletrans import Translator

if len(sys.argv) < 4:
    print("Invalid input")
    sys.exit(1)

src_lang = sys.argv[1]
tgt_lang = sys.argv[2]
text = ' '.join(sys.argv[3:])

translator = Translator()
translated = translator.translate(text, src=src_lang, dest=tgt_lang)
print(translated.text)
