from Crypto.Cipher import DES3
from Crypto.Random import get_random_bytes
def pad(text, block_size):
padding_size = block_size - len(text) % block_size
padding = bytes([padding_size] * padding_size)
return text + padding
def encrypt_3des_cbc(plaintext, key):
iv = get_random_bytes(8) # Initialization vector
cipher = DES3.new(key, DES3.MODE_CBC, iv)
ciphertext = cipher.encrypt(pad(plaintext, 8))
return iv + ciphertext
def decrypt_3des_cbc(ciphertext, key):
iv = ciphertext[:8]
ciphertext = ciphertext[8:]
cipher = DES3.new(key, DES3.MODE_CBC, iv)
decrypted = cipher.decrypt(ciphertext)
padding_size = decrypted[-1]
return decrypted[:-padding_size]
def main():
key = get_random_bytes(24) # 3DES requires a 24-byte key
plaintext = "Hello, this is a test message."

plaintext = plaintext.encode('utf-8')
encrypted = encrypt_3des_cbc(plaintext, key)
decrypted = decrypt_3des_cbc(encrypted, key).decode('utf-8')
print("Plaintext:", plaintext)
print("Encrypted:", encrypted.hex())
print("Decrypted:", decrypted)
if _name== "__main_":
main()
