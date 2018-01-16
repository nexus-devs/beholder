<p align="center">Layout detection framework for DirectX11 applications. Serves currently as a concept document.</p>

##

<br>

## Concepts
OK NEW CONCEPT MY DUDES:
* Feature Match
* If distance is high enough, template exists
* Template match
* Template match with scaling
* MASK ALGORITHM

Extremly professional concept art
![concept](/concept.png)

```js
// All scenes
scenes: [
    // Single scene object
    {
        // Name of the scene
        name: 'foundry',

        // Children objects
        objects: [
            // Single children object
            {
                name: 'item', // Name of the object
                template: 'foundry_item.jpg',   // Template image
                mask: 'foundry_item_mask.jpg',  // Mask of the template
                // This could theoretically be made out of the transparent zone in the template

                states: [ // States the item has
                    { // Single state	
                        // Still not sure about this section
                        // Could be done with templates, or params, or both
                        name: 'building', // item.building
                        conditions: [ // Conditions to meet
                            {
                                function: 'ocr',
                                match: 'BUILD',
                                params: [280, 80, 300, 100],
                            },
                            ...
                        ],
                    }
                ],
            },
            ...
        ],
    },
    ...
],
```

<br>

## License
[MIT](/LICENSE.md)