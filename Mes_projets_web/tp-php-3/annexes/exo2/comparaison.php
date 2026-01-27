<?php
$langues = [
    [
        'anglais',
        [
            'o' => 248,
            'e' => 355,
            'i' => 222,
            'u' => 107,
            'a' => 198
        ]
    ],
    [
        'français',
        [
            'o' => 178,
            'e' => 435,
            'i' => 240,
            'u' => 212,
            'a' => 201
        ]
    ],
    [
        'gallois',
        [
            'o' => 152,
            'e' => 264,
            'i' => 221,
            'u' => 107,
            'a' => 266
        ]
    ],
    [
        'samoan',
        [
            'o' => 248,
            'e' => 308,
            'i' => 334,
            'u' => 208,
            'a' => 656
        ]
    ],
    [
        'zoulou',
        [
            'o' => 203,
            'e' => 298,
            'i' => 311,
            'u' => 274,
            'a' => 411
        ]
    ]
];

// A COMPLETER

// TESTS
$voyelles = [
    'o',
    'e',
    'i',
    'u',
    'a'
];
usort($langues, "compare");
echo "Tri selon l'ordre " . implode(',', $voyelles) . ":\n";
print_r(array_map(function ($v) {
    return $v[0];
}, $langues));

sort($voyelles);
usort($langues, "compare");
echo "Tri selon l'ordre " . implode(',', $voyelles) . ":\n";
print_r(array_map(function ($v) {
    return $v[0];
}, $langues));
?>