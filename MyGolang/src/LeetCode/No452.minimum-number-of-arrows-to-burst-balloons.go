/**
No452. 用最少数量的箭引爆气球
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，
因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。
一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，且满足
xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。弓箭一旦被射出之后，可以无限地前进。
我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
给你一个数组 points ，其中 points [i] = [xstart, xend] ，返回引爆所有气球所必须射出的最小弓箭数。

示例 1：
输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球

示例 2：
输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4

示例 3：
输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2

示例 4：
输入：points = [[1,2]]
输出：1

示例 5：
输入：points = [[2,3],[2,3]]
输出：1

提示：
0 <= points.length <= 10^4
points[i].length == 2
-2^31 <= xstart < xend <= 2^31 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
package LeetCode
import "sort"

/**
 * 力扣路人解题思路：
 * 1. 把所有的气球按照右边界的大小进行排序。
 * 2. 然后把第一支箭尽可能的往第一个气球的右边靠，这样第一支箭引爆气球的数量就是最多的。
 * 3. 第二支箭要尽可能的往第二个气球（这里不是排序后的第二个气球，这里的第二个气球是和第一个气球坐标没有交集的那个气球）的右边靠……
 */

// 自定义二维气球数组类型，并重写sort函数的：Len(), Less(), Swap()
type myBalloons [][]int

func (arr myBalloons) Len() int {
    return len(arr)
}

func (arr myBalloons) Less(i, j int) bool {
    return arr[i][1] < arr[j][1]
}

func (arr myBalloons) Swap(i, j int) {
    arr[i][0], arr[j][0] = arr[j][0], arr[i][0]
    arr[i][1], arr[j][1] = arr[j][1], arr[i][1]
}

func findMinArrowShots(points [][]int) int {
    if len(points) == 0 {
        return 0
    }
    var m myBalloons = points
    // 排序（按 xstart 排序），sort.Interface接口
    sort.Sort(m)
    var count int = 1
    // 记录第一个气球最右边的位置（贪心）
    var last int = m[0][1]
    // 遍历数组
    for i := 1; i < len(m); i++ {
        // 找到第二个起始气球（下一个不能被上一个最右一箭引爆的气球）
        if last < m[i][0] {
            count++
            last = m[i][1] // 更新第二个起始气球的最右位置
        }
    }
    return count
}

/**
力扣官解
 */
func findMinArrowShotsOrigin(points [][]int) int {
    if len(points) == 0 {
        return 0
    }
    sort.Slice(points, func(i, j int) bool { return points[i][1] < points[j][1] })
    maxRight := points[0][1]
    ans := 1
    for _, p := range points {
        if p[0] > maxRight {
            maxRight = p[1]
            ans++
        }
    }
    return ans
}