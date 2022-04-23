public class Codec {

   static int N = 6;
    String alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    String key = getRandomStringOfLengthN();
    HashMap<String,String> hm = new HashMap<>();

    String getRandomStringOfLengthN()
    {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(alphabet.charAt((int)(Math.random()*62)));
        }

        return sb.toString();
    }
    

    public String encode(String longUrl) {
        
        while (hm.containsKey(key)) {
            key = getRandomStringOfLengthN();
        }
        hm.put(key, longUrl);
        return "https://tiny.url/" + key;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return hm.get(shortUrl.replace("https://tiny.url/", ""));
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));