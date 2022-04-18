import React from 'react';
import { Grid } from '@mui/material'
import Anagram from './Anagram';

function AnagramsView({ anagrams }) {
    const cards = anagrams.map(anagram => <Grid key={anagram} item><Anagram word={anagram} /></Grid>);
    return (
        <Grid container spacing={2} justifyContent={'center'}>
            {cards}
        </Grid>
    )
}

export default AnagramsView