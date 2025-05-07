==============================
LANGUAGE TRANSLATOR PROJECT
==============================

1. Install Requirements:
   pip install googletrans==4.0.0-rc1
----if facing error in this use the commands in sequence
i) mkdir language_translator_project
ii) cd language_translator_project
iii) python3 -m venv venv
iv) source venv/bin/activate
v) venv\Scripts\activate
vi) pip install googletrans==4.0.0-rc1


2. Compile the C programs:
   gcc server.c -o server
   gcc client.c -o client

3. Run the server:
   ./server

4. In another terminal, run the client:
   ./client

5. Enter:
   - Source language code (e.g., en for English)
   - Target language code (e.g., es for Spanish)
   - Text to translate

6. The server will return the translated text using Google Translate.

Language Codes Supported (examples):
------------------------------------
en - English
es - Spanish
fr - French
hi - Hindi
zh - Chinese
de - German
ja - Japanese
ar - Arabic
ru - Russian
ko - Korean
pt - Portuguese
bn - Bengali
tr - Turkish
id - Indonesian
ur - Urdu
