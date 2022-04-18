import React from 'react';
import { AppBar, Box, Toolbar, Typography, Button, IconButton } from '@mui/material';

function AppHeader() {
  return (
    <Box sx={{ flexGrow: 1 }}>
      <AppBar>
        <Toolbar sx = {{
            display: 'flex',
            justifyContent: 'space-between'
        }}>
            <Box>
                {/* <img src='/public/uficon.png'/>  TODO: Figure out how to get this in good */}
            </Box>
            <Box>
                <h1>Anagramagator</h1>
            </Box>
        </Toolbar>
      </AppBar>
    </Box>
  )
}

export default AppHeader;
