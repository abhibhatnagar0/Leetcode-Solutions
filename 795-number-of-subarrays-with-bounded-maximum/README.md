<h2><a href="https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/">795. Number of Subarrays with Bounded Maximum</a></h2><h3>Medium</h3><hr><div><p>Given an integer array <code>nums</code> and two integers <code>left</code> and <code>right</code>, return <em>the number of contiguous non-empty <strong>subarrays</strong> such that the value of the maximum array element in that subarray is in the range </em><code>[left, right]</code>.</p>

<p>The test cases are generated so that the answer will fit in a <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre style="position: relative;"><strong>Input:</strong> nums = [2,1,4,3], left = 2, right = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three subarrays that meet the requirements: [2], [2, 1], [3].
<div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><strong>Example 2:</strong></p>

<pre style="position: relative;"><strong>Input:</strong> nums = [2,9,2,5,6], left = 2, right = 8
<strong>Output:</strong> 7
<div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= left &lt;= right &lt;= 10<sup>9</sup></code></li>
</ul>
</div>