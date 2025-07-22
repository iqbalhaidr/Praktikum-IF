public class Email {
    private String email;

    public Email(String email) {
        this.email = email;
    };

    public boolean validateEmail() throws InvalidEmailException, InvalidDomainException {
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
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu
         * buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */
        int atCount = 0;
        int atIdx = 0;
        for (int i = 0; i < email.length(); i++) {
            if (email.charAt(i) == '@') {
                atCount++;
                atIdx = i;
            }
        }

        int dotCount = 0;
        int dotIdx = 0;
        for (int j = atIdx; j < email.length(); j++) {
            if (email.charAt(j) == '.') {
                dotCount++;
                dotIdx = j;
            }
        }

        boolean isValidChar = true;
        for (int k = 0; k < email.length(); k++) {
            if (!Character.isLetterOrDigit(email.charAt(k))) {
                isValidChar = false;
                break;
            }
        }

        if (email.length() <= 0) {
            throw new InvalidEmailException("Email tidak boleh kosong");
        }

        if (atCount != 1) {
            throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        }

        if (atIdx == 0) {
            throw new InvalidEmailException("@ tidak boleh di awal email");
        }

        if (dotCount != 1) {
            throw new InvalidDomainException();
        }

        if ((dotIdx == (email.length() - 1)) || (dotIdx == (atIdx + 1))) {
            throw new InvalidDomainException();
        }

        return true;
    }

}

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {
        // Implementasi InvalidEmailException
        super(message);
    }
}

class InvalidDomainException extends Exception {
    public String getMessage() {
        // Implementasi custom message InvalidDomainException
        // Return pesan multak berisi: "Email harus memiliki domain yang valid
        return "Email harus memiliki domain yang valid";
    }
}