from django.db import models 


class Light(models.Model):
    
    led = models.BooleanField(default = False)
    
    
    def __str__(self):
        return str(self.id)