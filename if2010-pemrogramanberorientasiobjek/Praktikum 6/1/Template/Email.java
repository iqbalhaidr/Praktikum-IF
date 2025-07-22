public class Email {
    private String email; 
    public Email(String email) {

    };
    
    public boolean validateEmail() {
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         * 
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */
    }

}

class InvalidEmailException {
    public InvalidEmailException(String message) {
        // Implementasi InvalidEmailException
    }
}

class InvalidDomainException {
    public String getMessage() {
        // Implementasi custom message InvalidDomainException
        // Return pesan multak berisi: "Email harus memiliki domain yang valid
    }
}