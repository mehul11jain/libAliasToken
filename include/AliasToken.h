#ifndef ALIASTOKEN_H
#define ALIASTOKEN_H

#include "Alias.h"
#include "llvm/IR/Argument.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Value.h"
#include "set"
#include "string"

namespace AliasUtil {

class AliasTokens {
   private:
    std::map<std::string, Alias*> AliasBank;
    bool isCached(Alias*);
    bool insert(Alias*);

   public:
    Alias* getAliasToken(llvm::Value*);
    Alias* getAliasToken(llvm::Argument*);
    Alias* getAliasToken(llvm::Type*);
    Alias* getAliasToken(llvm::Instruction*);
    Alias* getAliasToken(Alias*);
    Alias* getAliasToken(std::string, llvm::Function*);

    std::vector<Alias*> extractAliasToken(llvm::Instruction*);
    std::vector<Alias*> extractAliasToken(llvm::StoreInst*);
    std::vector<Alias*> extractAliasToken(llvm::LoadInst*);
    std::vector<Alias*> extractAliasToken(llvm::AllocaInst*);
    std::vector<Alias*> extractAliasToken(llvm::BitCastInst*);
    std::vector<Alias*> extractAliasToken(llvm::ReturnInst*);
    std::vector<Alias*> extractAliasToken(llvm::GetElementPtrInst*);
    std::vector<Alias*> extractAliasToken(llvm::GlobalVariable*);
    std::vector<Alias*> extractAliasToken(llvm::CallInst*);
    std::vector<Alias*> extractAliasToken(llvm::Argument*, llvm::Function*);

    template <typename Ty>
    std::pair<int, int> extractStatementType(Ty*);

    template <typename GEP>
    Alias* handleGEPUtil(GEP*, Alias*);

    ~AliasTokens();
};

}  // namespace AliasUtil

#endif
