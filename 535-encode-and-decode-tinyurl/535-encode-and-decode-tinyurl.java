class Codec {

    HashMap<String,Integer> encode = new HashMap<>();
    HashMap<Integer,String> decode = new HashMap<>();
    private int counter = 0;
    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {

        encode.put(longUrl, counter);
        decode.put(counter, longUrl);
        int retVal = counter;
        counter++;

        return "" + retVal;
        
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {

        int temp = Integer.parseInt(shortUrl);

        return decode.get(temp);
        
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));