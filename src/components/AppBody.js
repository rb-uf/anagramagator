import React, { useState } from 'react';
import { Input, Box, InputLabel, MenuItem, FormControl, Select, TextField, Button } from '@mui/material';
import AnagramsView from './AnagramsView';

function AppBody() {
    const [algorithm, setAlgorithm] = useState('bruteforce');
    const [word, setWord] = useState('');
    const [anagrams, setAnagrams] = useState(['bag', 'tag', 'zigzag']);
    const [error, setError] = useState(false);

    const handleSelect = (event) => {
        console.log(`Set Algorithm: ${event.target.value}`)
        setAlgorithm(event.target.value); // bruteforce = Default and anatree = Optimized
    };
    const handleInput = (event) => {
        console.log(event.target.value)
        setWord(event.target.value);
    };
    const onSubmit = (event) => {
        if(word !== '') {
            console.log(`Generate Anagrams for: ${word}`);
            console.log(`Generate Anagrams using: ${algorithm} algorithm`);
            anagrams.push(word);
            setWord('');
            setAlgorithm('bruteforce');
            setAnagrams([]);
        }
        else {
            setError(true);
        }
    }

    return (
        <>
            <Box sx={{ padding: 5 }}>
                <h2>Enter a word to find its anagrams!</h2>
                <Box 
                sx={{
                display: 'flex',
                flexDirection: 'column',
                alignItems: 'center',
                }}
                >
                    <Box
                    sx={{
                    display: 'flex',
                    justifyContent: 'space-between',
                    marginBottom: 3
                    }}>
                        <FormControl sx={{ m: 2 }} fullWidth>
                            <TextField id='outlined-search' label='Word' onChange={handleInput} value={word}/>
                        </FormControl>
                        <FormControl sx={{ m : 2}} fullWidth>
                            <InputLabel id="select">Algorithm</InputLabel>
                            <Select
                            labelId="select"
                            id="demo-simple-select"
                            value={algorithm}
                            label="algorithm"
                            onChange={handleSelect}
                            >
                                <MenuItem value={'bruteforce'}>Default</MenuItem>
                                <MenuItem value={'anatree'}>Optimized</MenuItem>
                            </Select>
                        </FormControl>
                    </Box>
                    <Box>
                        <Button variant='contained' onClick={onSubmit}>Generate Anagrams</Button>
                    </Box>
                </Box>
            </Box>
            {
            anagrams.length > 0
            &&
            <Box>
                <h1>Anagrams</h1>
                <AnagramsView anagrams={anagrams}/>
            </Box>
            }
        </>
    );
}

export default AppBody;

