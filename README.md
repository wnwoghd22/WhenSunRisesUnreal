# When Sun Rises

with Unreal Engine

---

Jay All Rights Reserved.

Original Project: https://github.com/wnwoghd22/WhenSunRises

from v0.5+, I decided to develop this with `Unreal engine`.

Roadmap

+ HUD

    + HUD class
    
    + HUD interface

+ Interactable

    **TODO: Well, I need to make an UML first.** (2024.01.08~)

    + Interactable Object

        + IInteractable Interface

        + Extends to Blueprint

    + Inventory

        + InventoryItem class

            + `TObjectPtr<InventoryItemData>` ItemData

        + Inventory class

            + `TMap<FName, InventoryItem>` Items

        + InventoryItem Data Asset

    + Dialogue system

        + Data Asset or File I/O

    + Choice system

        + how to implement `Multi Ending`?

+ Design

    + Environment Design

        + Map Design

        TODO: need to brush up on `unreal sensei environment course` (2024.01.09~)

        + Buildings

            + Watch tower

            + Storage

    + Characters

        + Meta Human

        TODO: learn `Meta Human` (2024.01.15~)

    + Cinematics

        + animations

        + sequencer
        
        TODO: learn `Sequencer` (2024.01.09~)