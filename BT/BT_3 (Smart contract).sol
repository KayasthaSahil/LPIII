// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.18;

contract SimpleBank {
    address public owner;                   //variable to store the address of the contract owner.

    constructor() {                         //It sets the 'owner' to the address that deployed the contract.
        owner = msg.sender;                 //'msg.sender' is the address of the person deploying the contract.
    }

    function showBalance() public view returns (uint) {                             //Show the total balance of Ether held by this contract. return The current balance in Wei. This is a 'view' function, meaning it only reads data and costs no gas to call.
        // 'address(this).balance' refers to the balance of the contract itself.
        return address(this).balance;
    }

    function deposit() public payable {                                            //Deposit Ether into the contract. This function is 'payable', which allows it to receive Ether. We add a security check to ensure only the owner can deposit. // Note: The Ether transfer is handled automatically because the function is 'payable' and the user sent Ether (msg.value) when calling it. No further code is needed to accept the Ether.
        require(msg.sender == owner, "Only the owner can deposit.");
    }

    function withdraw(uint _amount) public {                                       //Withdraw a specific amount of Ether from the contract. Only the owner can withdraw, and only if the contract has enough funds. parameter: _amount - The amount of Ether (in Wei) to withdraw.
        require(msg.sender == owner, "Only the owner can withdraw.");
        require(address(this).balance >= _amount, "Insufficient funds in contract.");

        payable(owner).transfer(_amount);       //// Send the Ether.'payable(owner)' converts the owner's address to a payable address. '.transfer(_amount)' sends the specified amount to that address.                                
    }