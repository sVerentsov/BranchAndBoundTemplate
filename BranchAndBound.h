#pragma once
template<typename LocalVariable, typename Answer>
class BranchAndBound
{
public:
	virtual bool nextBranch(LocalVariable* lv) = 0;
	virtual bool BoundingFunction(LocalVariable* lv) = 0;
	virtual LocalVariable* preprocessing() = 0;
	virtual void postProcessing(LocalVariable* lv) = 0;
	virtual void cancelBranch(LocalVariable* lv) = 0;
	Answer curAnswer;
	void branchAndBound();
};

template <typename LocalVariable, typename Answer>
void BranchAndBound<LocalVariable, Answer>::branchAndBound()
{
	LocalVariable* lv = preprocessing();
	while (nextBranch(lv))
		if (BoundingFunction(lv))
			branchAndBound();
		else
			cancelBranch(lv);
	postProcessing(lv);
}
