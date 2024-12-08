fun main() {
    println(sum(5, 3))
    println(greet("Alice"))
}

fun sum(a: Int, b: Int): Int {
    return a + b
}

fun greet(name: String): String {
    return "Hello, $name!"
}
