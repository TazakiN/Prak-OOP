public class Palindrome<T> {
    // Method untuk mengecek apakah Deque dq merupakan palindrome
    // Deque dq merupakan palindrome jika elemen-elemen pada Deque dq dapat dibaca
    // sama dari depan dan belakang
    public boolean isPalindrome(Deque<T> dq) {
        boolean isPalindrome = true;
        while (dq.size() > 1) {
            try {
                T depan = dq.popFront();
                T belakang = dq.popBack();
                if (!depan.equals(belakang)) {
                    isPalindrome = false;
                    break;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return isPalindrome;
    }
}