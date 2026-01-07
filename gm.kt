import java.io.BufferedInputStream
import java.lang.StringBuilder
import kotlin.math.max

private const val BUFFER_SIZE = 1 shl 16

private class FastScanner {
    private val input = BufferedInputStream(System.`in`, BUFFER_SIZE)
    private val buffer = ByteArray(BUFFER_SIZE)
    private var len = 0
    private var ptr = 0

    private fun readByte(): Int {
        if (ptr >= len) {
            len = input.read(buffer)
            ptr = 0
            if (len <= 0) return -1
        }
        return buffer[ptr++].toInt()
    }

    fun nextLong(): Long {
        var c: Int
        do {
            c = readByte()
        } while (c <= 32)

        var sign = 1
        var res = 0L
        var ch = c
        if (ch == '-'.code) {
            sign = -1
            ch = readByte()
        }
        while (ch > 32) {
            res = res * 10 + (ch - '0'.code)
            ch = readByte()
        }
        return res * sign
    }
}

private fun lowerBound(arr: LongArray, x: Long): Int {
    var l = 0
    var r = arr.size
    while (l < r) {
        val mid = (l + r) ushr 1
        if (arr[mid] < x) l = mid + 1
        else r = mid
    }
    return l
}

private fun solve(fs: FastScanner, out: StringBuilder) {
    val n = fs.nextLong().toInt()
    val m = fs.nextLong().toInt()

    val freq = LongArray(101)
    var common = 0L

    val a = LongArray(n)
    val b = LongArray(m)

    for (i in 0 until n) {
        val x = fs.nextLong()
        a[i] = x
        freq[x.toInt()]++
    }

    for (i in 0 until m) {
        val x = fs.nextLong()
        b[i] = x
        freq[x.toInt()]++
        if (freq[x.toInt()] == 2L) {
            common = x
        }
    }

    val idxA = lowerBound(a, common)
    val idxB = lowerBound(b, common)

    val choserA = max(idxA, n - idxA - 1)
    val choserB = max(idxB, m - idxB - 1)

    val ans = when {
        choserA < choserB -> 2 * choserA + 1
        choserB < choserA -> 2 * choserB + 2
        else -> 2 * choserA + 1
    }

    out.append(ans).append('\n')
}

fun main() {
    val fs = FastScanner()
    val out = StringBuilder()

    val t = fs.nextLong().toInt()
    repeat(t) {
        solve(fs, out)
    }

    print(out.toString())
}
