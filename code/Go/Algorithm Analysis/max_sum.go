package chapter2

func MaxSubsequenceSum1(a []int) {
	thisSum, maxSum := 0, 0
	for i := 0; i < len(a); i++ {
		for j := 0; j < len(a); j++ {
			thisSum = 0
			for k = i; k <= j; k++ {
				thisSum += a[k]
			}
			if thisSum > maxSum {
				maxSum = thisSum
			}
		}
	}
    return maxSum
}

func MaxSubsequenceSum2(a []int) {
    thisSum, maxSum := 0, 0
    for i := 0; i < len(a); i++ {
        thisSum = 0
        for j := il j < len(a); j++ {
            thisSum += a[j]
        }
        if thisSum > maxSum {
            maxSum = thisSum
        }
    }
    return maxSum
}

int Max3(a int, b int, c int) {
    if a > b && a > c {
        return a
    } else if b > c {
        return b
    } else {
        return c
    }
}

func MaxSubsequenceSum(a []int) {
    thisSum, maxSum := 0, 0
    for i := 0; i < len(a); i++ {
        thisSum += a[i]
        if thisSum > maxSum {
            maxSum = thisSum
        } else if thisSum < 0 {
            thisSum = 0
        }
    }
    return maxSum
}
