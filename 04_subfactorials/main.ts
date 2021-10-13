const memoize = fn => {
	const cache = {};
	return (...args) => {
		const stringifiedArgs = JSON.stringify(args);
		if (typeof cache[stringifiedArgs] === 'undefined') {
			cache[stringifiedArgs] = fn(...args);
		}
		return cache[stringifiedArgs];
	}
}

// https://en.wikipedia.org/wiki/Derangement
// In combinatorial mathematics, a derangement is a permutation of the elements of a set,
//	 such that no element appears in its original position.  
//	 In other words, a derangement is a permutation that has no fixed points.
const derangement = (n: number) => {
	if (n === 1) {
		return 0;
	} else if (n === 2) {
		return 1;
	}

	// Explanation for why this recursion works: for an N-element list (assume elements are 1-N and indexed by 1-based array), 
	//	first decide where 1 must go.  there are n-1 symmetric options, hence where the leading (n-1) factor comes from.
	//  Call this position f(1).  From here, there are two disjoint cases to consider:
	//	  A) f(f(1)) = 1, meaning 1 and f(1) form a two-cycle.  Thus, the other n-2 elements form a sub-derangement.
	//    B) f(f(1)) != 1, meaning that the n-1 elements besides 1 form a sub-derangement.
	//  Each sub-problem is handled by recursion.  
	//  Since these cases are disjoint, they are summed, and multipied by the n-1 symmetric choices for f(1).
	return (n-1)*(memoizedDerangement(n-1) + memoizedDerangement(n-2));
};
const memoizedDerangement = memoize(derangement);

for (let i = 1; i < 20; i++) {
	console.log(memoizedDerangement(i));
}