transactions = []
balances = {}
max_transaction = ('X', 'Y', float('-Inf'))

def transfer(sender, receiver, amount):
    transactions.append((sender,receiver, amount))
    if not sender in balances:
        balances[sender] = 0
    if not receiver in balances:
        balances[receiver] = 0
    balances[sender] -= amount
    balances[receiver] += amount
    if amount > max_transaction[2]:
        max_transaction = (sender, receiver, amount)
    
def get_balance(user):
    return balances[user]